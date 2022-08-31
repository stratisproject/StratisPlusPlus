#include "StratisDemo.h"

#include "NFTContractByteCode.h"

#include "blockchain/TransactionBuilderFactory.h"

namespace stratis {

namespace {
const char* CIRRUS_MAINNET_URI = "https://api-sfn.stratisphere.com";
const char* CIRRUS_TESTNET_URI = "https://api-sfn-test.stratisphere.com";

const char* DEFAULT_MNEMONIC = "glad brave cheese solar vocal certain whip problem else across service tail";

} // namespace

StratisDemo::StratisDemo()
    : stratisManager(StratisDemo::createStratisManager(DEFAULT_MNEMONIC, true))
{
}

void StratisDemo::runDemo()
{
    std::cout << "*********** WELCOME TO STRATIS++ DEMO PROJECT ***********" << std::endl;

    bool shouldQuit = false;
    do {
        shouldQuit = this->handleInput();
    } while (!shouldQuit);
}

bool StratisDemo::handleInput()
{
    this->displayCommandList();

    int command = -1;
    std::cin >> command;

    switch (command) {
    case 0:
        this->handleQuitCommand();
        return true;
    case 1:
        this->handleLoginCommand();
        break;
    case 2:
        this->handleShowAddressCommand();
        break;
    case 3:
        this->handleShowBalanceCommand();
        break;
    case 4:
        this->handleSendCoinsCommand();
        break;
    case 5:
        this->handleShowOwnedNFTsCommand();
        break;
    case 6:
        this->handleDeployNFTContractCommand();
        break;
    case 7:
        this->handleSendNFTCommand();
        break;
    default:
        this->handleUnrecognizedCommand();
        break;
    }

    std::cout << std::endl
              << "################################################################################"
              << std::endl
              << std::endl;

    return false;
}

void StratisDemo::displayCommandList()
{
    std::cout << "Commands:" << std::endl
              << "(1) Login to wallet" << std::endl
              << "(2) Show my address" << std::endl
              << "(3) Show my balance" << std::endl
              << "(4) Send coins to address" << std::endl
              << "(5) Show owned NFTs" << std::endl
              << "(6) Deploy NFT contract" << std::endl
              << "(7) Send NFT to address" << std::endl
              << "(0) Quit" << std::endl;
}

void StratisDemo::handleLoginCommand()
{
    std::cout << "Choose network:" << std::endl
              << "(1) MainNet" << std::endl
              << "(2) TestNet" << std::endl;

    int network = 0;
    std::cin >> network;
    if (network != 1 && network != 2) {
        std::cout << "Invalid option, MainNet will be used instead." << std::endl;
    }

    std::cout << "Enter mnemonic:" << std::endl;
    std::string mnemonic;

    std::cin >> mnemonic;

    std::shared_ptr<StratisManager> stratisManagerPtr = nullptr;
    try {
        stratisManagerPtr = createStratisManager(mnemonic, network == 2);
    } catch (const std::exception& e) {
        std::cout << "Error occured while initializing wallet" << std::endl;
        return;
    }

    if (stratisManagerPtr != nullptr) {
        stratisManager = std::move(stratisManagerPtr);
    }

    std::cout << "Wallet initlized successfuly." << std::endl;
}

void StratisDemo::handleShowAddressCommand()
{
    std::cout << "Current address: " << stratisManager->getAddress() << std::endl;
}

void StratisDemo::handleShowBalanceCommand()
{
    std::cout << "Current balance: ";

    stratisManager->getBalance()
        .then([](pplx::task<uint64_t> task) {
            uint64_t balance = 0;
            balance = task.get();

            try {
                std::cout << (double)balance / 10000 << "CRS" << std::endl;
            } catch (const std::exception& e) {
                std::cout << "unknown" << std::endl;
                std::cerr << e.what() << std::endl;
            }
        })
        .wait();
}

void StratisDemo::handleSendCoinsCommand()
{
    std::cout << "Recipient address: " << std::endl;

    std::string address;
    std::cin >> address;

    std::cout << std::endl
              << "Amount to send (in satoshis): "
              << std::endl;

    uint64_t amount = 0;
    std::cin >> amount;
    std::cout << std::endl;

    stratisManager->sendCoinsTransaction(address, amount)
        .then([](pplx::task<std::string> task) {
            try {
                auto txID = task.get();
                std::cout << "Coins sent." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Error has occurred. Coins not sent." << std::endl;
                std::cerr << e.what() << std::endl;
            }
        })
        .wait();
}


void StratisDemo::handleShowOwnedNFTsCommand()
{
    std::cout << "Owned NFTs:" << std::endl;
    stratisManager->getOwnedNFTs(stratisManager->getAddress())
        .then([](std::shared_ptr<OwnedNFTs> ownedNFTs) {
            if (ownedNFTs != nullptr) {
                for (const auto& entry : ownedNFTs->ownedIDsByContractAddress) {
                    std::cout << "NFT contract: " << entry.first
                              << " , IDs: [";
                    for (size_t i = 0; i < entry.second.size(); i++) {
                        std::cout << entry.second[i];
                        if (i != entry.second.size() - 1) {
                            std::cout << ", ";
                        }
                    }
                    std::cout << "]";
                }
            } else {
                std::cout << "Nothing found." << std::endl;
            }
        })
        .wait();
}

void StratisDemo::handleDeployNFTContractCommand()
{
    std::cout << "Enter NFT collection name:" << std::endl;
    std::string name;
    std::cin >> name;

    std::cout << "Enter NFT collection symbol:" << std::endl;
    std::string symbol;
    std::cin >> symbol;

    std::cout << "Allow non-owner minting? [y/n] (no by default):" << std::endl;
    std::string allowNonOwnerMinting;
    std::cin >> allowNonOwnerMinting;

    bool allowNonOwnerMintingValue = false;

    if (allowNonOwnerMinting == "y" || allowNonOwnerMinting == "yes") {
        allowNonOwnerMintingValue = true;
    }

    std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>> parameters;
    parameters.push_back(smart_contracts::method_parameter::convert(name));
    parameters.push_back(smart_contracts::method_parameter::convert(symbol));
    parameters.push_back(smart_contracts::method_parameter::convert(allowNonOwnerMintingValue));

    stratisManager->sendCreateContractTransaction(NFT_CONTRACT_CODE,
                                                  std::move(parameters),
                                                  0)
        .wait();
}

void StratisDemo::handleSendNFTCommand()
{
    std::cout << "Enter NFT contract address:" << std::endl;
    std::string contractAddress;
    std::cin >> contractAddress;

    std::cout << "Enter recipient address:" << std::endl;
    std::string recipientAddress;
    std::cin >> recipientAddress;

    std::cout << "Enter token id:" << std::endl;
    std::string tokenID;
    std::cin >> tokenID;

    std::vector<std::unique_ptr<smart_contracts::method_parameter::MethodParameter>> parameters;
    parameters.push_back(smart_contracts::method_parameter::convert(Address(stratisManager->getAddress())));
    parameters.push_back(smart_contracts::method_parameter::convert(Address(recipientAddress)));
    parameters.push_back(smart_contracts::method_parameter::convert(UInt256(tokenID)));

    stratisManager->sendCallContractTransaction(
                      contractAddress,
                      "SafeTransferFrom",
                      std::move(parameters),
                      0)
        .then([this](std::string transactionID) {
            return this->stratisManager->waitForReceipt(transactionID);
        })
        .wait();
}

void StratisDemo::handleQuitCommand()
{
    std::cout << "Quit..." << std::endl;
}

void StratisDemo::handleUnrecognizedCommand()
{
    std::cout << "Unrecognized command" << std::endl;
}

std::shared_ptr<stratis::StratisManager> StratisDemo::createStratisManager(const std::string& mnemonic, bool runOnTestnet)
{
    auto configuration(std::make_shared<stratis::api::ApiConfiguration>());
    configuration->setBaseUrl(runOnTestnet ? CIRRUS_TESTNET_URI : CIRRUS_MAINNET_URI);

    auto apiClient(std::make_shared<stratis::api::ApiClient>(configuration));
    auto unrealApi(std::make_shared<stratis::api::UnrealApi>(apiClient));

    auto transactionBuilder(stratis::createTransactionBuilder(
        mnemonic,
        runOnTestnet ? stratis::StratisNetwork::CIRRUS_TEST : stratis::StratisNetwork::CIRRUS));

    return std::make_shared<stratis::StratisManager>(unrealApi, transactionBuilder);
}

std::shared_ptr<StratisManager> StratisDemo::createStratisManager(const char* mnemonic, bool runOnTestnet)
{
    std::string mnemonicString(mnemonic);
    return StratisDemo::createStratisManager(mnemonicString, runOnTestnet);
}

} // namespace stratis
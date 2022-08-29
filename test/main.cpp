#include "StratisManager.h"

#include "blockchain/TransactionBuilderFactory.h"

#include <iostream>
#include <memory>

int main(int, char**)
{
    auto configuration(std::make_shared<stratis::api::ApiConfiguration>());
    configuration->setBaseUrl("https://api-sfn-test.stratisphere.com");

    auto apiClient(std::make_shared<stratis::api::ApiClient>(configuration));
    auto unrealApi(std::make_shared<stratis::api::UnrealApi>(apiClient));

    auto transactionBuilder(stratis::createTransactionBuilder(
        "glad brave cheese solar vocal certain whip problem else across service tail",
        stratis::StratisNetwork::CIRRUS_TEST));

    auto stratisManager(std::make_shared<stratis::StratisManager>(unrealApi, transactionBuilder));

    std::cout << "Hello, world!\n";

    std::cout << "My address: " << stratisManager->getAddress() << std::endl;

    stratisManager->getCoins();

    std::cout << "My balance: " << std::endl;

    std::string input;

    std::cin >> input;

    return 0;
}

// Copyright © 2022 Stratis Platform.
//
// This file is part of Stratis++ SDK. The full copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE-STRATIS at the root of the source code distribution tree.

#include "engine/WalletImpl.h"
#include "engine/Coin.h"
#include "engine/HexCoding.h"
#include "engine/Mnemonic.h"
#include "engine/Signer.h"

namespace stratis {
namespace engine {


constexpr uint32_t DEFAULT_SEQUENCE = std::numeric_limits<uint32_t>::max();

WalletImpl::WalletImpl(const std::string& mnemonic, TWCoinType coinType)
    : hdWallet_(TW::HDWallet(mnemonic, "", false)),
      coinType_(coinType)
{
}

std::string WalletImpl::generateMnemonic() const
{
    return TW::Mnemonic::generateMnemonic();
}

std::string WalletImpl::getMnemonic() const
{
    return hdWallet_.getMnemonic();
}

void WalletImpl::setMnemonic(const std::string& mnemonic)
{
    hdWallet_ = TW::HDWallet(mnemonic, "", false);
}

TWCoinType WalletImpl::getCoinType() const
{
    return coinType_;
}

void WalletImpl::setCoinType(TWCoinType coinType)
{
    coinType_ = coinType;
}

std::string WalletImpl::getAddress() const
{
    return hdWallet_.deriveAddress(coinType_);
}

BuiltTransaction WalletImpl::createSendCoinsTransaction(const WalletUTXOs& utxos, std::string destinationAddress, uint64_t amount) const
{
    auto signingInput(this->buildSigningInput(utxos));
    signingInput.amount = amount;
    signingInput.toAddress = destinationAddress;
    return this->signTransaction(signingInput);
}

BuiltTransaction WalletImpl::createOpReturnTransaction(const WalletUTXOs& utxos, const TW::Data& opReturnData) const
{
    auto signingInput(this->buildSigningInput(utxos));
    signingInput.outputOpReturn = opReturnData;
    return this->signTransaction(signingInput);
}

BuiltTransaction WalletImpl::createCustomScriptTransaction(const WalletUTXOs& utxos,
                                                           const TW::Data& customScript,
                                                           uint64_t amount,
                                                           uint64_t gasPrice,
                                                           uint64_t gasLimit) const
{
    auto signingInput(this->buildSigningInput(utxos));
    signingInput.amount = amount;
    signingInput.outputCustomScript = TW::Bitcoin::Script(customScript);
    signingInput.gasPrice = gasPrice;
    signingInput.gasLimit = gasLimit;

    return this->signTransaction(signingInput);
}

TW::Bitcoin::SigningInput WalletImpl::buildSigningInput(const WalletUTXOs& utxos) const
{
    TW::Bitcoin::SigningInput signingInput;

    auto coin = this->getCoinType();

    signingInput.changeAddress = this->getAddress();
    signingInput.coinType = coin;

    signingInput.privateKeys = {hdWallet_.getKey(coin, TW::derivationPath(coin))};

    TW::Bitcoin::UTXOs convertedUtxos;
    convertedUtxos.reserve(utxos.size());

    for (const auto& utxo : utxos) {
        TW::Bitcoin::OutPoint outpoint{
            TW::reverse(TW::parse_hex(utxo.hash)),
            utxo.n,
            DEFAULT_SEQUENCE};

        convertedUtxos.push_back({outpoint, TW::Bitcoin::Script::lockScriptForAddress(this->getAddress(), coin),
                                  static_cast<TW::Bitcoin::Amount>(utxo.satoshis)});
    }

    signingInput.utxos = convertedUtxos;

    return signingInput;
}

BuiltTransaction WalletImpl::signTransaction(const TW::Bitcoin::SigningInput& input) const
{
    auto signedOutput = TW::Bitcoin::Signer::sign(input);

    return BuiltTransaction{
        signedOutput.transactionId,
        TW::hex(signedOutput.encoded)};
}

std::shared_ptr<Wallet> createWallet(const std::string& mnemonic, TWCoinType coinType)
{
    return std::make_shared<WalletImpl>(mnemonic, coinType);
}

} // namespace engine
} // namespace stratis
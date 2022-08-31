#pragma once

#include "StratisManager.h"

#include <iostream>
#include <memory>
#include <string>

namespace stratis {

class StratisDemo
{
public:
    StratisDemo();

    void runDemo();

private:
    bool handleInput();

    void displayCommandList();

    void handleLoginCommand();
    void handleShowAddressCommand();
    void handleShowBalanceCommand();
    void handleSendCoinsCommand();
    void handleShowOwnedNFTsCommand();
    void handleDeployNFTContractCommand();
    void handleSendNFTCommand();
    void handleQuitCommand();
    void handleUnrecognizedCommand();

    static std::shared_ptr<StratisManager> createStratisManager(const std::string& mnemonic, bool runOnTestnet = false);
    static std::shared_ptr<StratisManager> createStratisManager(const char* mnemonic, bool runOnTestnet = false);

    std::shared_ptr<StratisManager> stratisManager;
};

} // namespace stratis

#pragma once

#include "Address.h"

#include <cstdint>
#include <map>
#include <vector>


namespace stratis {

class OwnedNFTs
{
public:
    OwnedNFTs();
    OwnedNFTs(const std::map<std::string, std::vector<uint64_t>>& ownedIDsByContractAddressArg);
    OwnedNFTs(std::map<std::string, std::vector<uint64_t>>&& ownedIDsByContractAddressArg);

    std::map<std::string, std::vector<uint64_t>> ownedIDsByContractAddress;
};

} // namespace stratis
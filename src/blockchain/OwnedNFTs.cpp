#include "blockchain/OwnedNFTs.h"

namespace stratis {

OwnedNFTs::OwnedNFTs()
{
}

OwnedNFTs::OwnedNFTs(const std::map<std::string, std::vector<uint64_t>>& ownedIDsByContractAddressArg)
    : ownedIDsByContractAddress(ownedIDsByContractAddressArg)
{
}

OwnedNFTs::OwnedNFTs(std::map<std::string, std::vector<uint64_t>>&& ownedIDsByContractAddressArg)
    : ownedIDsByContractAddress(std::move(ownedIDsByContractAddressArg))
{
}

} // namespace stratis
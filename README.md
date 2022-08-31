# Stratis++

This is an official C++ SDK for Stratis Blockchain Platform.

> If you are looking for a plugin for Unreal Engine, [check this repository](https://github.com/stratisproject/UnrealEnginePlugin).

## Components reference

 - `StratisManager` - is an entry-point class for any interaction with Stratis Blockchain. It contains all necessary functions for building and sending transactions, interaction with smart contracts etc.
 - `blockchain/` - contains Stratis-specific code (mainly smart contracts interaction logic).
 - `engine/` - blockchain engine based on [Trust Wallet Core project](https://github.com/trustwallet/wallet-core).
 - `lightweightapi/` - contains auto-generated wrappers for HTTP API calls.
 - `pplx/` - contains some utilities for Concurency API.
 - `trezor/` - cryptography engine based on [Trezor project](https://github.com/trezor/trezor-firmware/tree/master/crypto)
 
## Examples

Please check demo project (`demo/` folder) for more details.
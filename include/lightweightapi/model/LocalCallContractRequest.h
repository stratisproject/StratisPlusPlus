/**
 * Stratis Node API
 * Access to the Stratis Node's api.
 *
 * The version of the OpenAPI document: 1.0
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 6.0.0.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * LocalCallContractRequest.h
 *
 * A class containing the necessary parameters to perform a local smart contract
 * method call request.
 */

#ifndef STRATIS_API_MODEL_LocalCallContractRequest_H_
#define STRATIS_API_MODEL_LocalCallContractRequest_H_

#include "lightweightapi/ModelBase.h"

#include <cpprest/details/basic_types.h>
#include <vector>

namespace stratis {
namespace api {
namespace model {

/// <summary>
/// A class containing the necessary parameters to perform a local smart
/// contract method call request.
/// </summary>
class LocalCallContractRequest : public ModelBase
{
public:
    LocalCallContractRequest();
    virtual ~LocalCallContractRequest();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart,
                     const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart,
                       const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// LocalCallContractRequest members

    /// <summary>
    /// The height at which to query the contract&#39;s state. If unset, will
    /// default to the current chain tip.
    /// </summary>
    int64_t getBlockHeight() const;
    bool blockHeightIsSet() const;
    void unsetBlockHeight();

    void setBlockHeight(int64_t value);

    /// <summary>
    /// The address of the smart contract containing the method.
    /// </summary>
    utility::string_t getContractAddress() const;
    bool contractAddressIsSet() const;
    void unsetContractAddress();

    void setContractAddress(const utility::string_t& value);

    /// <summary>
    /// The name of the method to call.
    /// </summary>
    utility::string_t getMethodName() const;
    bool methodNameIsSet() const;
    void unsetMethodName();

    void setMethodName(const utility::string_t& value);

    /// <summary>
    /// The amount of STRAT (or sidechain coin) to send to the smart contract
    /// address.   No funds are actually sent, but the Amount field allows certain
    /// scenarios, where the funds sent dictates the result, to be checked.
    /// </summary>
    utility::string_t getAmount() const;
    bool amountIsSet() const;
    void unsetAmount();

    void setAmount(const utility::string_t& value);

    /// <summary>
    /// The gas price to use. This is used to calculate the expected expenditure
    /// if the method is run by a miner mining a call transaction rather than
    /// locally.
    /// </summary>
    int64_t getGasPrice() const;
    bool gasPriceIsSet() const;
    void unsetGasPrice();

    void setGasPrice(int64_t value);

    /// <summary>
    /// The maximum amount of gas that can be spent executing this transaction.
    /// Although the gas expenditure is theoretical rather than actual,  this
    /// limit cannot be exceeded even when the method is run locally.
    /// </summary>
    int64_t getGasLimit() const;
    bool gasLimitIsSet() const;
    void unsetGasLimit();

    void setGasLimit(int64_t value);

    /// <summary>
    /// A wallet address containing the funds to cover transaction fees, gas, and
    /// any funds specified in the  Amount field.  Note that because the method
    /// call is local no funds are spent. However, the concept of the sender
    /// address  is still valid and may need to be checked.  For example, some
    /// methods, such as a withdrawal method on an escrow smart contract, should
    /// only be executed  by the deployer, and in this case, it is the Sender
    /// address that identifies the deployer.
    /// </summary>
    utility::string_t getSender() const;
    bool senderIsSet() const;
    void unsetSender();

    void setSender(const utility::string_t& value);

    /// <summary>
    /// An array of encoded strings containing the parameters (and their type) to
    /// pass to the smart contract  method when it is called. More information on
    /// the  format of a parameter string is available  &lt;a
    /// target&#x3D;\&quot;_blank\&quot;
    /// href&#x3D;\&quot;https://academy.stratisplatform.com/SmartContracts/working-with-contracts.html#parameter-serialization\&quot;&gt;here&lt;/a&gt;.
    /// </summary>
    std::vector<utility::string_t>& getParameters();
    bool parametersIsSet() const;
    void unsetParameters();

    void setParameters(const std::vector<utility::string_t>& value);

protected:
    int64_t m_BlockHeight;
    bool m_BlockHeightIsSet;
    utility::string_t m_ContractAddress;
    bool m_ContractAddressIsSet;
    utility::string_t m_MethodName;
    bool m_MethodNameIsSet;
    utility::string_t m_Amount;
    bool m_AmountIsSet;
    int64_t m_GasPrice;
    bool m_GasPriceIsSet;
    int64_t m_GasLimit;
    bool m_GasLimitIsSet;
    utility::string_t m_Sender;
    bool m_SenderIsSet;
    std::vector<utility::string_t> m_Parameters;
    bool m_ParametersIsSet;
};

} // namespace model
} // namespace api
} // namespace stratis

#endif /* STRATIS_API_MODEL_LocalCallContractRequest_H_ */

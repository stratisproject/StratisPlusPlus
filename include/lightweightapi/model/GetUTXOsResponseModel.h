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
 * GetUTXOsResponseModel.h
 *
 *
 */

#ifndef STRATIS_API_MODEL_GetUTXOsResponseModel_H_
#define STRATIS_API_MODEL_GetUTXOsResponseModel_H_

#include "lightweightapi/ModelBase.h"

#include "lightweightapi/model/UTXOModel.h"
#include <cpprest/details/basic_types.h>
#include <vector>

namespace stratis {
namespace api {
namespace model {

class UTXOModel;

/// <summary>
///
/// </summary>
class GetUTXOsResponseModel : public ModelBase
{
public:
    GetUTXOsResponseModel();
    virtual ~GetUTXOsResponseModel();

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
    /// GetUTXOsResponseModel members

    /// <summary>
    ///
    /// </summary>
    int64_t getBalanceSat() const;
    bool balanceSatIsSet() const;
    void unsetBalanceSat();

    void setBalanceSat(int64_t value);

    /// <summary>
    ///
    /// </summary>
    std::vector<std::shared_ptr<UTXOModel>>& getUTXOs();
    bool uTXOsIsSet() const;
    void unsetUTXOs();

    void setUTXOs(const std::vector<std::shared_ptr<UTXOModel>>& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getReason() const;
    bool reasonIsSet() const;
    void unsetReason();

    void setReason(const utility::string_t& value);

protected:
    int64_t m_BalanceSat;
    bool m_BalanceSatIsSet;
    std::vector<std::shared_ptr<UTXOModel>> m_UTXOs;
    bool m_UTXOsIsSet;
    utility::string_t m_Reason;
    bool m_ReasonIsSet;
};

} // namespace model
} // namespace api
} // namespace stratis

#endif /* STRATIS_API_MODEL_GetUTXOsResponseModel_H_ */

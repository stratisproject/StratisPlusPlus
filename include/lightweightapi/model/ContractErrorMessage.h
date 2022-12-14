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
 * ContractErrorMessage.h
 *
 *
 */

#ifndef STRATIS_API_MODEL_ContractErrorMessage_H_
#define STRATIS_API_MODEL_ContractErrorMessage_H_

#include "lightweightapi/ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace stratis {
namespace api {
namespace model {

/// <summary>
///
/// </summary>
class ContractErrorMessage : public ModelBase
{
public:
    ContractErrorMessage();
    virtual ~ContractErrorMessage();

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
    /// ContractErrorMessage members

    /// <summary>
    ///
    /// </summary>
    utility::string_t getValue() const;
    bool valueIsSet() const;
    void unsetValue();

    void setValue(const utility::string_t& value);

protected:
    utility::string_t m_Value;
    bool m_ValueIsSet;
};

} // namespace model
} // namespace api
} // namespace stratis

#endif /* STRATIS_API_MODEL_ContractErrorMessage_H_ */

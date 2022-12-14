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

#include "lightweightapi/model/ContractErrorMessage.h"

namespace stratis {
namespace api {
namespace model {

ContractErrorMessage::ContractErrorMessage()
{
    m_Value = utility::conversions::to_string_t("");
    m_ValueIsSet = false;
}

ContractErrorMessage::~ContractErrorMessage() {}

void ContractErrorMessage::validate()
{
    // TODO: implement validation
}

web::json::value ContractErrorMessage::toJson() const
{
    web::json::value val = web::json::value::object();

    if (m_ValueIsSet) {
        val[utility::conversions::to_string_t(U("Value"))] =
            ModelBase::toJson(m_Value);
    }

    return val;
}

bool ContractErrorMessage::fromJson(const web::json::value& val)
{
    bool ok = true;

    if (val.has_field(utility::conversions::to_string_t(U("Value")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("Value")));
        if (!fieldValue.is_null()) {
            utility::string_t refVal_setValue;
            ok &= ModelBase::fromJson(fieldValue, refVal_setValue);
            setValue(refVal_setValue);
        }
    }
    return ok;
}

void ContractErrorMessage::toMultipart(
    std::shared_ptr<MultipartFormData> multipart,
    const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if (m_ValueIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("Value")), m_Value));
    }
}

bool ContractErrorMessage::fromMultiPart(
    std::shared_ptr<MultipartFormData> multipart,
    const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if (multipart->hasContent(utility::conversions::to_string_t(U("Value")))) {
        utility::string_t refVal_setValue;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(utility::conversions::to_string_t(U("Value"))),
            refVal_setValue);
        setValue(refVal_setValue);
    }
    return ok;
}

utility::string_t ContractErrorMessage::getValue() const { return m_Value; }

void ContractErrorMessage::setValue(const utility::string_t& value)
{
    m_Value = value;
    m_ValueIsSet = true;
}

bool ContractErrorMessage::valueIsSet() const { return m_ValueIsSet; }

void ContractErrorMessage::unsetValue() { m_ValueIsSet = false; }
} // namespace model
} // namespace api
} // namespace stratis

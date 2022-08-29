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

#include "lightweightapi/model/Money.h"

namespace stratis {
namespace api {
namespace model {

Money::Money()
{
    m_Satoshi = 0L;
    m_SatoshiIsSet = false;
}

Money::~Money() {}

void Money::validate()
{
    // TODO: implement validation
}

web::json::value Money::toJson() const
{
    web::json::value val = web::json::value::object();

    if (m_SatoshiIsSet) {
        val[utility::conversions::to_string_t(U("Satoshi"))] =
            ModelBase::toJson(m_Satoshi);
    }

    return val;
}

bool Money::fromJson(const web::json::value& val)
{
    bool ok = true;

    if (val.has_field(utility::conversions::to_string_t(U("Satoshi")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("Satoshi")));
        if (!fieldValue.is_null()) {
            int64_t refVal_setSatoshi;
            ok &= ModelBase::fromJson(fieldValue, refVal_setSatoshi);
            setSatoshi(refVal_setSatoshi);
        }
    }
    return ok;
}

void Money::toMultipart(std::shared_ptr<MultipartFormData> multipart,
                        const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if (m_SatoshiIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("Satoshi")),
            m_Satoshi));
    }
}

bool Money::fromMultiPart(std::shared_ptr<MultipartFormData> multipart,
                          const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if (multipart->hasContent(utility::conversions::to_string_t(U("Satoshi")))) {
        int64_t refVal_setSatoshi;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(utility::conversions::to_string_t(U("Satoshi"))),
            refVal_setSatoshi);
        setSatoshi(refVal_setSatoshi);
    }
    return ok;
}

int64_t Money::getSatoshi() const { return m_Satoshi; }

void Money::setSatoshi(int64_t value)
{
    m_Satoshi = value;
    m_SatoshiIsSet = true;
}

bool Money::satoshiIsSet() const { return m_SatoshiIsSet; }

void Money::unsetSatoshi() { m_SatoshiIsSet = false; }
} // namespace model
} // namespace api
} // namespace stratis
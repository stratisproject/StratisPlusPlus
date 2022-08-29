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

#include "lightweightapi/model/TipModel.h"

namespace stratis {
namespace api {
namespace model {

TipModel::TipModel()
{
    m_TipHash = utility::conversions::to_string_t("");
    m_TipHashIsSet = false;
    m_TipHeight = 0;
    m_TipHeightIsSet = false;
}

TipModel::~TipModel() {}

void TipModel::validate()
{
    // TODO: implement validation
}

web::json::value TipModel::toJson() const
{
    web::json::value val = web::json::value::object();

    if (m_TipHashIsSet) {
        val[utility::conversions::to_string_t(U("TipHash"))] =
            ModelBase::toJson(m_TipHash);
    }
    if (m_TipHeightIsSet) {
        val[utility::conversions::to_string_t(U("TipHeight"))] =
            ModelBase::toJson(m_TipHeight);
    }

    return val;
}

bool TipModel::fromJson(const web::json::value& val)
{
    bool ok = true;

    if (val.has_field(utility::conversions::to_string_t(U("TipHash")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("TipHash")));
        if (!fieldValue.is_null()) {
            utility::string_t refVal_setTipHash;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTipHash);
            setTipHash(refVal_setTipHash);
        }
    }
    if (val.has_field(utility::conversions::to_string_t(U("TipHeight")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("TipHeight")));
        if (!fieldValue.is_null()) {
            int32_t refVal_setTipHeight;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTipHeight);
            setTipHeight(refVal_setTipHeight);
        }
    }
    return ok;
}

void TipModel::toMultipart(std::shared_ptr<MultipartFormData> multipart,
                           const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if (m_TipHashIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("TipHash")),
            m_TipHash));
    }
    if (m_TipHeightIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("TipHeight")),
            m_TipHeight));
    }
}

bool TipModel::fromMultiPart(std::shared_ptr<MultipartFormData> multipart,
                             const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if (multipart->hasContent(utility::conversions::to_string_t(U("TipHash")))) {
        utility::string_t refVal_setTipHash;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(utility::conversions::to_string_t(U("TipHash"))),
            refVal_setTipHash);
        setTipHash(refVal_setTipHash);
    }
    if (multipart->hasContent(
            utility::conversions::to_string_t(U("TipHeight")))) {
        int32_t refVal_setTipHeight;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(
                utility::conversions::to_string_t(U("TipHeight"))),
            refVal_setTipHeight);
        setTipHeight(refVal_setTipHeight);
    }
    return ok;
}

utility::string_t TipModel::getTipHash() const { return m_TipHash; }

void TipModel::setTipHash(const utility::string_t& value)
{
    m_TipHash = value;
    m_TipHashIsSet = true;
}

bool TipModel::tipHashIsSet() const { return m_TipHashIsSet; }

void TipModel::unsetTipHash() { m_TipHashIsSet = false; }
int32_t TipModel::getTipHeight() const { return m_TipHeight; }

void TipModel::setTipHeight(int32_t value)
{
    m_TipHeight = value;
    m_TipHeightIsSet = true;
}

bool TipModel::tipHeightIsSet() const { return m_TipHeightIsSet; }

void TipModel::unsetTipHeight() { m_TipHeightIsSet = false; }
} // namespace model
} // namespace api
} // namespace stratis
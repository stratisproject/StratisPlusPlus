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

#include "StratisCPPLightClient/model/GetUTXOsResponseModel.h"

namespace stratis {
namespace api {
namespace model {

GetUTXOsResponseModel::GetUTXOsResponseModel() {
  m_BalanceSat = 0L;
  m_BalanceSatIsSet = false;
  m_UTXOsIsSet = false;
  m_Reason = utility::conversions::to_string_t("");
  m_ReasonIsSet = false;
}

GetUTXOsResponseModel::~GetUTXOsResponseModel() {}

void GetUTXOsResponseModel::validate() {
  // TODO: implement validation
}

web::json::value GetUTXOsResponseModel::toJson() const {

  web::json::value val = web::json::value::object();

  if (m_BalanceSatIsSet) {
    val[utility::conversions::to_string_t(U("BalanceSat"))] =
        ModelBase::toJson(m_BalanceSat);
  }
  if (m_UTXOsIsSet) {
    val[utility::conversions::to_string_t(U("UTXOs"))] =
        ModelBase::toJson(m_UTXOs);
  }
  if (m_ReasonIsSet) {
    val[utility::conversions::to_string_t(U("Reason"))] =
        ModelBase::toJson(m_Reason);
  }

  return val;
}

bool GetUTXOsResponseModel::fromJson(const web::json::value &val) {
  bool ok = true;

  if (val.has_field(utility::conversions::to_string_t(U("BalanceSat")))) {
    const web::json::value &fieldValue =
        val.at(utility::conversions::to_string_t(U("BalanceSat")));
    if (!fieldValue.is_null()) {
      int64_t refVal_setBalanceSat;
      ok &= ModelBase::fromJson(fieldValue, refVal_setBalanceSat);
      setBalanceSat(refVal_setBalanceSat);
    }
  }
  if (val.has_field(utility::conversions::to_string_t(U("UTXOs")))) {
    const web::json::value &fieldValue =
        val.at(utility::conversions::to_string_t(U("UTXOs")));
    if (!fieldValue.is_null()) {
      std::vector<std::shared_ptr<UTXOModel>> refVal_setUTXOs;
      ok &= ModelBase::fromJson(fieldValue, refVal_setUTXOs);
      setUTXOs(refVal_setUTXOs);
    }
  }
  if (val.has_field(utility::conversions::to_string_t(U("Reason")))) {
    const web::json::value &fieldValue =
        val.at(utility::conversions::to_string_t(U("Reason")));
    if (!fieldValue.is_null()) {
      utility::string_t refVal_setReason;
      ok &= ModelBase::fromJson(fieldValue, refVal_setReason);
      setReason(refVal_setReason);
    }
  }
  return ok;
}

void GetUTXOsResponseModel::toMultipart(
    std::shared_ptr<MultipartFormData> multipart,
    const utility::string_t &prefix) const {
  utility::string_t namePrefix = prefix;
  if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                   utility::conversions::to_string_t(U("."))) {
    namePrefix += utility::conversions::to_string_t(U("."));
  }
  if (m_BalanceSatIsSet) {
    multipart->add(ModelBase::toHttpContent(
        namePrefix + utility::conversions::to_string_t(U("BalanceSat")),
        m_BalanceSat));
  }
  if (m_UTXOsIsSet) {
    multipart->add(ModelBase::toHttpContent(
        namePrefix + utility::conversions::to_string_t(U("UTXOs")), m_UTXOs));
  }
  if (m_ReasonIsSet) {
    multipart->add(ModelBase::toHttpContent(
        namePrefix + utility::conversions::to_string_t(U("Reason")), m_Reason));
  }
}

bool GetUTXOsResponseModel::fromMultiPart(
    std::shared_ptr<MultipartFormData> multipart,
    const utility::string_t &prefix) {
  bool ok = true;
  utility::string_t namePrefix = prefix;
  if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                   utility::conversions::to_string_t(U("."))) {
    namePrefix += utility::conversions::to_string_t(U("."));
  }

  if (multipart->hasContent(
          utility::conversions::to_string_t(U("BalanceSat")))) {
    int64_t refVal_setBalanceSat;
    ok &= ModelBase::fromHttpContent(
        multipart->getContent(
            utility::conversions::to_string_t(U("BalanceSat"))),
        refVal_setBalanceSat);
    setBalanceSat(refVal_setBalanceSat);
  }
  if (multipart->hasContent(utility::conversions::to_string_t(U("UTXOs")))) {
    std::vector<std::shared_ptr<UTXOModel>> refVal_setUTXOs;
    ok &= ModelBase::fromHttpContent(
        multipart->getContent(utility::conversions::to_string_t(U("UTXOs"))),
        refVal_setUTXOs);
    setUTXOs(refVal_setUTXOs);
  }
  if (multipart->hasContent(utility::conversions::to_string_t(U("Reason")))) {
    utility::string_t refVal_setReason;
    ok &= ModelBase::fromHttpContent(
        multipart->getContent(utility::conversions::to_string_t(U("Reason"))),
        refVal_setReason);
    setReason(refVal_setReason);
  }
  return ok;
}

int64_t GetUTXOsResponseModel::getBalanceSat() const { return m_BalanceSat; }

void GetUTXOsResponseModel::setBalanceSat(int64_t value) {
  m_BalanceSat = value;
  m_BalanceSatIsSet = true;
}

bool GetUTXOsResponseModel::balanceSatIsSet() const {
  return m_BalanceSatIsSet;
}

void GetUTXOsResponseModel::unsetBalanceSat() { m_BalanceSatIsSet = false; }
std::vector<std::shared_ptr<UTXOModel>> &GetUTXOsResponseModel::getUTXOs() {
  return m_UTXOs;
}

void GetUTXOsResponseModel::setUTXOs(
    const std::vector<std::shared_ptr<UTXOModel>> &value) {
  m_UTXOs = value;
  m_UTXOsIsSet = true;
}

bool GetUTXOsResponseModel::uTXOsIsSet() const { return m_UTXOsIsSet; }

void GetUTXOsResponseModel::unsetUTXOs() { m_UTXOsIsSet = false; }
utility::string_t GetUTXOsResponseModel::getReason() const { return m_Reason; }

void GetUTXOsResponseModel::setReason(const utility::string_t &value) {
  m_Reason = value;
  m_ReasonIsSet = true;
}

bool GetUTXOsResponseModel::reasonIsSet() const { return m_ReasonIsSet; }

void GetUTXOsResponseModel::unsetReason() { m_ReasonIsSet = false; }
} // namespace model
} // namespace api
} // namespace stratis

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

#include "StratisCPPLightClient/model/SendTransactionRequest.h"

namespace stratis {
namespace api {
namespace model {

SendTransactionRequest::SendTransactionRequest() {
  m_Hex = utility::conversions::to_string_t("");
  m_HexIsSet = false;
}

SendTransactionRequest::~SendTransactionRequest() {}

void SendTransactionRequest::validate() {
  // TODO: implement validation
}

web::json::value SendTransactionRequest::toJson() const {

  web::json::value val = web::json::value::object();

  if (m_HexIsSet) {
    val[utility::conversions::to_string_t(U("Hex"))] = ModelBase::toJson(m_Hex);
  }

  return val;
}

bool SendTransactionRequest::fromJson(const web::json::value &val) {
  bool ok = true;

  if (val.has_field(utility::conversions::to_string_t(U("Hex")))) {
    const web::json::value &fieldValue =
        val.at(utility::conversions::to_string_t(U("Hex")));
    if (!fieldValue.is_null()) {
      utility::string_t refVal_setHex;
      ok &= ModelBase::fromJson(fieldValue, refVal_setHex);
      setHex(refVal_setHex);
    }
  }
  return ok;
}

void SendTransactionRequest::toMultipart(
    std::shared_ptr<MultipartFormData> multipart,
    const utility::string_t &prefix) const {
  utility::string_t namePrefix = prefix;
  if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                   utility::conversions::to_string_t(U("."))) {
    namePrefix += utility::conversions::to_string_t(U("."));
  }
  if (m_HexIsSet) {
    multipart->add(ModelBase::toHttpContent(
        namePrefix + utility::conversions::to_string_t(U("Hex")), m_Hex));
  }
}

bool SendTransactionRequest::fromMultiPart(
    std::shared_ptr<MultipartFormData> multipart,
    const utility::string_t &prefix) {
  bool ok = true;
  utility::string_t namePrefix = prefix;
  if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                   utility::conversions::to_string_t(U("."))) {
    namePrefix += utility::conversions::to_string_t(U("."));
  }

  if (multipart->hasContent(utility::conversions::to_string_t(U("Hex")))) {
    utility::string_t refVal_setHex;
    ok &= ModelBase::fromHttpContent(
        multipart->getContent(utility::conversions::to_string_t(U("Hex"))),
        refVal_setHex);
    setHex(refVal_setHex);
  }
  return ok;
}

utility::string_t SendTransactionRequest::getHex() const { return m_Hex; }

void SendTransactionRequest::setHex(const utility::string_t &value) {
  m_Hex = value;
  m_HexIsSet = true;
}

bool SendTransactionRequest::hexIsSet() const { return m_HexIsSet; }

void SendTransactionRequest::unsetHex() { m_HexIsSet = false; }
} // namespace model
} // namespace api
} // namespace stratis

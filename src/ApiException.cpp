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

#include "StratisCPPLightClient/ApiException.h"

namespace stratis {
namespace api {

ApiException::ApiException(int errorCode, const utility::string_t &message,
                           std::shared_ptr<std::istream> content /*= nullptr*/)
    : web::http::http_exception(errorCode, message), m_Content(content) {}
ApiException::ApiException(
    int errorCode, const utility::string_t &message,
    std::map<utility::string_t, utility::string_t> &headers,
    std::shared_ptr<std::istream> content /*= nullptr*/)
    : web::http::http_exception(errorCode, message), m_Content(content),
      m_Headers(headers) {}

ApiException::~ApiException() {}

std::shared_ptr<std::istream> ApiException::getContent() const {
  return m_Content;
}

std::map<utility::string_t, utility::string_t> &ApiException::getHeaders() {
  return m_Headers;
}

} // namespace api
} // namespace stratis

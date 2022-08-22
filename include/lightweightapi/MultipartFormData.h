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
 * MultipartFormData.h
 *
 * This class represents a container for building
 * application/x-multipart-formdata requests.
 */

#ifndef STRATIS_API_MODEL_MultipartFormData_H_
#define STRATIS_API_MODEL_MultipartFormData_H_

#include "StratisCPPLightClient/HttpContent.h"
#include "StratisCPPLightClient/IHttpBody.h"

#include <cpprest/details/basic_types.h>

#include <map>
#include <memory>
#include <vector>

namespace stratis {
namespace api {
namespace model {

class MultipartFormData : public IHttpBody {
public:
  MultipartFormData();
  MultipartFormData(const utility::string_t &boundary);
  virtual ~MultipartFormData();

  virtual void add(std::shared_ptr<HttpContent> content);
  virtual utility::string_t getBoundary();
  virtual std::shared_ptr<HttpContent>
  getContent(const utility::string_t &name) const;
  virtual bool hasContent(const utility::string_t &name) const;
  virtual void writeTo(std::ostream &target);

protected:
  std::vector<std::shared_ptr<HttpContent>> m_Contents;
  utility::string_t m_Boundary;
  std::map<utility::string_t, std::shared_ptr<HttpContent>> m_ContentLookup;
};

} // namespace model
} // namespace api
} // namespace stratis

#endif /* STRATIS_API_MODEL_MultipartFormData_H_ */
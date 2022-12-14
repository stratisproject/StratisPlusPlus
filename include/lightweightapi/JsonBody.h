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
 * JsonBody.h
 *
 * This is a JSON http body which can be submitted via http
 */

#ifndef STRATIS_API_MODEL_JsonBody_H_
#define STRATIS_API_MODEL_JsonBody_H_

#include "lightweightapi/IHttpBody.h"

#include <cpprest/json.h>

namespace stratis {
namespace api {
namespace model {

class JsonBody : public IHttpBody
{
public:
    JsonBody(const web::json::value& value);
    virtual ~JsonBody();

    void writeTo(std::ostream& target) override;

protected:
    web::json::value m_Json;
};

} // namespace model
} // namespace api
} // namespace stratis

#endif /* STRATIS_API_MODEL_JsonBody_H_ */

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
 * ProblemDetails.h
 *
 *
 */

#ifndef STRATIS_API_MODEL_ProblemDetails_H_
#define STRATIS_API_MODEL_ProblemDetails_H_

#include "lightweightapi/ModelBase.h"

#include <cpprest/details/basic_types.h>
#include <map>

namespace stratis {
namespace api {
namespace model {

/// <summary>
///
/// </summary>
class ProblemDetails : public ModelBase
{
public:
    ProblemDetails();
    virtual ~ProblemDetails();

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
    /// ProblemDetails members

    /// <summary>
    ///
    /// </summary>
    utility::string_t getType() const;
    bool typeIsSet() const;
    void unsetType();

    void setType(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getTitle() const;
    bool titleIsSet() const;
    void unsetTitle();

    void setTitle(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    int32_t getStatus() const;
    bool statusIsSet() const;
    void unsetStatus();

    void setStatus(int32_t value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getDetail() const;
    bool detailIsSet() const;
    void unsetDetail();

    void setDetail(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getInstance() const;
    bool instanceIsSet() const;
    void unsetInstance();

    void setInstance(const utility::string_t& value);

protected:
    utility::string_t m_Type;
    bool m_TypeIsSet;
    utility::string_t m_Title;
    bool m_TitleIsSet;
    int32_t m_Status;
    bool m_StatusIsSet;
    utility::string_t m_Detail;
    bool m_DetailIsSet;
    utility::string_t m_Instance;
    bool m_InstanceIsSet;
};

} // namespace model
} // namespace api
} // namespace stratis

#endif /* STRATIS_API_MODEL_ProblemDetails_H_ */

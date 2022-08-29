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

#include "lightweightapi/model/LogData.h"

namespace stratis {
namespace api {
namespace model {

LogData::LogData()
{
    m_Event = utility::conversions::to_string_t("");
    m_EventIsSet = false;
    m_DataIsSet = false;
}

LogData::~LogData() {}

void LogData::validate()
{
    // TODO: implement validation
}

web::json::value LogData::toJson() const
{
    web::json::value val = web::json::value::object();

    if (m_EventIsSet) {
        val[utility::conversions::to_string_t(U("Event"))] =
            ModelBase::toJson(m_Event);
    }
    if (m_DataIsSet) {
        val[utility::conversions::to_string_t(U("Data"))] =
            ModelBase::toJson(m_Data);
    }

    return val;
}

bool LogData::fromJson(const web::json::value& val)
{
    bool ok = true;

    if (val.has_field(utility::conversions::to_string_t(U("Event")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("Event")));
        if (!fieldValue.is_null()) {
            utility::string_t refVal_setEvent;
            ok &= ModelBase::fromJson(fieldValue, refVal_setEvent);
            setEvent(refVal_setEvent);
        }
    }
    if (val.has_field(utility::conversions::to_string_t(U("Data")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("Data")));
        if (!fieldValue.is_null()) {
            std::map<utility::string_t, std::shared_ptr<Object>> refVal_setData;
            ok &= ModelBase::fromJson(fieldValue, refVal_setData);
            setData(refVal_setData);
        }
    }
    return ok;
}

void LogData::toMultipart(std::shared_ptr<MultipartFormData> multipart,
                          const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if (m_EventIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("Event")), m_Event));
    }
    if (m_DataIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("Data")), m_Data));
    }
}

bool LogData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart,
                            const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if (multipart->hasContent(utility::conversions::to_string_t(U("Event")))) {
        utility::string_t refVal_setEvent;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(utility::conversions::to_string_t(U("Event"))),
            refVal_setEvent);
        setEvent(refVal_setEvent);
    }
    if (multipart->hasContent(utility::conversions::to_string_t(U("Data")))) {
        std::map<utility::string_t, std::shared_ptr<Object>> refVal_setData;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(utility::conversions::to_string_t(U("Data"))),
            refVal_setData);
        setData(refVal_setData);
    }
    return ok;
}

utility::string_t LogData::getEvent() const { return m_Event; }

void LogData::setEvent(const utility::string_t& value)
{
    m_Event = value;
    m_EventIsSet = true;
}

bool LogData::eventIsSet() const { return m_EventIsSet; }

void LogData::unsetEvent() { m_EventIsSet = false; }
std::map<utility::string_t, std::shared_ptr<Object>>& LogData::getData()
{
    return m_Data;
}

void LogData::setData(
    const std::map<utility::string_t, std::shared_ptr<Object>>& value)
{
    m_Data = value;
    m_DataIsSet = true;
}

bool LogData::dataIsSet() const { return m_DataIsSet; }

void LogData::unsetData() { m_DataIsSet = false; }
} // namespace model
} // namespace api
} // namespace stratis

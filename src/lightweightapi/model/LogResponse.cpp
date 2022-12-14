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

#include "lightweightapi/model/LogResponse.h"

namespace stratis {
namespace api {
namespace model {

LogResponse::LogResponse()
{
    m_Address = utility::conversions::to_string_t("");
    m_AddressIsSet = false;
    m_TopicsIsSet = false;
    m_Data = utility::conversions::to_string_t("");
    m_DataIsSet = false;
    m_LogIsSet = false;
}

LogResponse::~LogResponse() {}

void LogResponse::validate()
{
    // TODO: implement validation
}

web::json::value LogResponse::toJson() const
{
    web::json::value val = web::json::value::object();

    if (m_AddressIsSet) {
        val[utility::conversions::to_string_t(U("Address"))] =
            ModelBase::toJson(m_Address);
    }
    if (m_TopicsIsSet) {
        val[utility::conversions::to_string_t(U("Topics"))] =
            ModelBase::toJson(m_Topics);
    }
    if (m_DataIsSet) {
        val[utility::conversions::to_string_t(U("Data"))] =
            ModelBase::toJson(m_Data);
    }
    if (m_LogIsSet) {
        val[utility::conversions::to_string_t(U("Log"))] = ModelBase::toJson(m_Log);
    }

    return val;
}

bool LogResponse::fromJson(const web::json::value& val)
{
    bool ok = true;

    if (val.has_field(utility::conversions::to_string_t(U("Address")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("Address")));
        if (!fieldValue.is_null()) {
            utility::string_t refVal_setAddress;
            ok &= ModelBase::fromJson(fieldValue, refVal_setAddress);
            setAddress(refVal_setAddress);
        }
    }
    if (val.has_field(utility::conversions::to_string_t(U("Topics")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("Topics")));
        if (!fieldValue.is_null()) {
            std::vector<utility::string_t> refVal_setTopics;
            ok &= ModelBase::fromJson(fieldValue, refVal_setTopics);
            setTopics(refVal_setTopics);
        }
    }
    if (val.has_field(utility::conversions::to_string_t(U("Data")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("Data")));
        if (!fieldValue.is_null()) {
            utility::string_t refVal_setData;
            ok &= ModelBase::fromJson(fieldValue, refVal_setData);
            setData(refVal_setData);
        }
    }
    if (val.has_field(utility::conversions::to_string_t(U("Log")))) {
        const web::json::value& fieldValue =
            val.at(utility::conversions::to_string_t(U("Log")));
        if (!fieldValue.is_null()) {
            std::shared_ptr<LogData> refVal_setLog;
            ok &= ModelBase::fromJson(fieldValue, refVal_setLog);
            setLog(refVal_setLog);
        }
    }
    return ok;
}

void LogResponse::toMultipart(std::shared_ptr<MultipartFormData> multipart,
                              const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }
    if (m_AddressIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("Address")),
            m_Address));
    }
    if (m_TopicsIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("Topics")), m_Topics));
    }
    if (m_DataIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("Data")), m_Data));
    }
    if (m_LogIsSet) {
        multipart->add(ModelBase::toHttpContent(
            namePrefix + utility::conversions::to_string_t(U("Log")), m_Log));
    }
}

bool LogResponse::fromMultiPart(std::shared_ptr<MultipartFormData> multipart,
                                const utility::string_t& prefix)
{
    bool ok = true;
    utility::string_t namePrefix = prefix;
    if (namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) !=
                                     utility::conversions::to_string_t(U("."))) {
        namePrefix += utility::conversions::to_string_t(U("."));
    }

    if (multipart->hasContent(utility::conversions::to_string_t(U("Address")))) {
        utility::string_t refVal_setAddress;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(utility::conversions::to_string_t(U("Address"))),
            refVal_setAddress);
        setAddress(refVal_setAddress);
    }
    if (multipart->hasContent(utility::conversions::to_string_t(U("Topics")))) {
        std::vector<utility::string_t> refVal_setTopics;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(utility::conversions::to_string_t(U("Topics"))),
            refVal_setTopics);
        setTopics(refVal_setTopics);
    }
    if (multipart->hasContent(utility::conversions::to_string_t(U("Data")))) {
        utility::string_t refVal_setData;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(utility::conversions::to_string_t(U("Data"))),
            refVal_setData);
        setData(refVal_setData);
    }
    if (multipart->hasContent(utility::conversions::to_string_t(U("Log")))) {
        std::shared_ptr<LogData> refVal_setLog;
        ok &= ModelBase::fromHttpContent(
            multipart->getContent(utility::conversions::to_string_t(U("Log"))),
            refVal_setLog);
        setLog(refVal_setLog);
    }
    return ok;
}

utility::string_t LogResponse::getAddress() const { return m_Address; }

void LogResponse::setAddress(const utility::string_t& value)
{
    m_Address = value;
    m_AddressIsSet = true;
}

bool LogResponse::addressIsSet() const { return m_AddressIsSet; }

void LogResponse::unsetAddress() { m_AddressIsSet = false; }
std::vector<utility::string_t>& LogResponse::getTopics() { return m_Topics; }

void LogResponse::setTopics(const std::vector<utility::string_t>& value)
{
    m_Topics = value;
    m_TopicsIsSet = true;
}

bool LogResponse::topicsIsSet() const { return m_TopicsIsSet; }

void LogResponse::unsetTopics() { m_TopicsIsSet = false; }
utility::string_t LogResponse::getData() const { return m_Data; }

void LogResponse::setData(const utility::string_t& value)
{
    m_Data = value;
    m_DataIsSet = true;
}

bool LogResponse::dataIsSet() const { return m_DataIsSet; }

void LogResponse::unsetData() { m_DataIsSet = false; }
std::shared_ptr<LogData> LogResponse::getLog() const { return m_Log; }

void LogResponse::setLog(const std::shared_ptr<LogData>& value)
{
    m_Log = value;
    m_LogIsSet = true;
}

bool LogResponse::logIsSet() const { return m_LogIsSet; }

void LogResponse::unsetLog() { m_LogIsSet = false; }
} // namespace model
} // namespace api
} // namespace stratis

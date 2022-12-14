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
 * BlockModel.h
 *
 *
 */

#ifndef STRATIS_API_MODEL_BlockModel_H_
#define STRATIS_API_MODEL_BlockModel_H_

#include "lightweightapi/ModelBase.h"
#include "lightweightapi/Object.h"

#include <cpprest/details/basic_types.h>
#include <vector>

namespace stratis {
namespace api {
namespace model {

/// <summary>
///
/// </summary>
class BlockModel : public ModelBase
{
public:
    BlockModel();
    virtual ~BlockModel();

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
    /// BlockModel members

    /// <summary>
    ///
    /// </summary>
    utility::string_t getHash() const;
    bool hashIsSet() const;
    void unsetHash();

    void setHash(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    int32_t getConfirmations() const;
    bool confirmationsIsSet() const;
    void unsetConfirmations();

    void setConfirmations(int32_t value);

    /// <summary>
    ///
    /// </summary>
    int32_t getSize() const;
    bool sizeIsSet() const;
    void unsetSize();

    void setSize(int32_t value);

    /// <summary>
    ///
    /// </summary>
    int64_t getWeight() const;
    bool weightIsSet() const;
    void unsetWeight();

    void setWeight(int64_t value);

    /// <summary>
    ///
    /// </summary>
    int32_t getHeight() const;
    bool heightIsSet() const;
    void unsetHeight();

    void setHeight(int32_t value);

    /// <summary>
    ///
    /// </summary>
    int32_t getVersion() const;
    bool versionIsSet() const;
    void unsetVersion();

    void setVersion(int32_t value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getVersionHex() const;
    bool versionHexIsSet() const;
    void unsetVersionHex();

    void setVersionHex(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getMerkleroot() const;
    bool merklerootIsSet() const;
    void unsetMerkleroot();

    void setMerkleroot(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    std::vector<std::shared_ptr<Object>>& getTx();
    bool txIsSet() const;
    void unsetTx();

    void setTx(const std::vector<std::shared_ptr<Object>>& value);

    /// <summary>
    ///
    /// </summary>
    int64_t getTime() const;
    bool timeIsSet() const;
    void unsetTime();

    void setTime(int64_t value);

    /// <summary>
    ///
    /// </summary>
    int64_t getMediantime() const;
    bool mediantimeIsSet() const;
    void unsetMediantime();

    void setMediantime(int64_t value);

    /// <summary>
    ///
    /// </summary>
    int32_t getNonce() const;
    bool nonceIsSet() const;
    void unsetNonce();

    void setNonce(int32_t value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getBits() const;
    bool bitsIsSet() const;
    void unsetBits();

    void setBits(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    double getDifficulty() const;
    bool difficultyIsSet() const;
    void unsetDifficulty();

    void setDifficulty(double value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getChainwork() const;
    bool chainworkIsSet() const;
    void unsetChainwork();

    void setChainwork(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    int32_t getNTx() const;
    bool nTxIsSet() const;
    void unsetNTx();

    void setNTx(int32_t value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getPreviousblockhash() const;
    bool previousblockhashIsSet() const;
    void unsetPreviousblockhash();

    void setPreviousblockhash(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getNextblockhash() const;
    bool nextblockhashIsSet() const;
    void unsetNextblockhash();

    void setNextblockhash(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getSignature() const;
    bool signatureIsSet() const;
    void unsetSignature();

    void setSignature(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getModifierv2() const;
    bool modifierv2IsSet() const;
    void unsetModifierv2();

    void setModifierv2(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getFlags() const;
    bool flagsIsSet() const;
    void unsetFlags();

    void setFlags(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getHashproof() const;
    bool hashproofIsSet() const;
    void unsetHashproof();

    void setHashproof(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getBlocktrust() const;
    bool blocktrustIsSet() const;
    void unsetBlocktrust();

    void setBlocktrust(const utility::string_t& value);

    /// <summary>
    ///
    /// </summary>
    utility::string_t getChaintrust() const;
    bool chaintrustIsSet() const;
    void unsetChaintrust();

    void setChaintrust(const utility::string_t& value);

protected:
    utility::string_t m_Hash;
    bool m_HashIsSet;
    int32_t m_Confirmations;
    bool m_ConfirmationsIsSet;
    int32_t m_Size;
    bool m_SizeIsSet;
    int64_t m_Weight;
    bool m_WeightIsSet;
    int32_t m_Height;
    bool m_HeightIsSet;
    int32_t m_Version;
    bool m_VersionIsSet;
    utility::string_t m_VersionHex;
    bool m_VersionHexIsSet;
    utility::string_t m_Merkleroot;
    bool m_MerklerootIsSet;
    std::vector<std::shared_ptr<Object>> m_Tx;
    bool m_TxIsSet;
    int64_t m_Time;
    bool m_TimeIsSet;
    int64_t m_Mediantime;
    bool m_MediantimeIsSet;
    int32_t m_Nonce;
    bool m_NonceIsSet;
    utility::string_t m_Bits;
    bool m_BitsIsSet;
    double m_Difficulty;
    bool m_DifficultyIsSet;
    utility::string_t m_Chainwork;
    bool m_ChainworkIsSet;
    int32_t m_NTx;
    bool m_NTxIsSet;
    utility::string_t m_Previousblockhash;
    bool m_PreviousblockhashIsSet;
    utility::string_t m_Nextblockhash;
    bool m_NextblockhashIsSet;
    utility::string_t m_Signature;
    bool m_SignatureIsSet;
    utility::string_t m_Modifierv2;
    bool m_Modifierv2IsSet;
    utility::string_t m_Flags;
    bool m_FlagsIsSet;
    utility::string_t m_Hashproof;
    bool m_HashproofIsSet;
    utility::string_t m_Blocktrust;
    bool m_BlocktrustIsSet;
    utility::string_t m_Chaintrust;
    bool m_ChaintrustIsSet;
};

} // namespace model
} // namespace api
} // namespace stratis

#endif /* STRATIS_API_MODEL_BlockModel_H_ */

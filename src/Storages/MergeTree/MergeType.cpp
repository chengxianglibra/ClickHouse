#include <Storages/MergeTree/MergeType.h>
#include <Common/Exception.h>

namespace DB
{

namespace ErrorCodes
{
    extern const int NOT_IMPLEMENTED;
}

String toString(MergeType merge_type)
{
    switch (merge_type)
    {
    case MergeType::NORMAL:
        return "NORMAL";
    case MergeType::TTL_DELETE:
        return "TTL_DELETE";
    case MergeType::TTL_RECOMPRESS:
        return "TTL_RECOMPRESS";
    }

    throw Exception(ErrorCodes::NOT_IMPLEMENTED, "Unknown MergeType {}", static_cast<UInt64>(merge_type));
}

bool isTTLMergeType(MergeType merge_type)
{
    return merge_type == MergeType::TTL_DELETE || merge_type == MergeType::TTL_RECOMPRESS;
}

}
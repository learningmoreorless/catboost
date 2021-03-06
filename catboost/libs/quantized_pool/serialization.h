#pragma once

#include <util/generic/fwd.h>
#include <util/stream/fwd.h>

namespace NCB {
    struct TQuantizedPool;
    struct TQuantizedPoolDigest;

    namespace NIdl {
        class TPoolQuantizationSchema;
    }
}

namespace NCB {
    void SaveQuantizedPool(const TQuantizedPool& pool, IOutputStream* output);

    struct TLoadQuantizedPoolParameters {
        bool LockMemory{true};
        bool Precharge{true};
    };

    // Load quantized pool saved by `SaveQuantizedPool` from file.
    TQuantizedPool LoadQuantizedPool(TStringBuf path, const TLoadQuantizedPoolParameters& params);
    NIdl::TPoolQuantizationSchema LoadQuantizationSchema(TStringBuf path);
    TQuantizedPoolDigest CalculateQuantizedPoolDigest(TStringBuf path);
}

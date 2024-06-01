#pragma once

#include <array>
#include <string>

#include "../utils.hpp"

using BlockId = uint8_t;

namespace Block {

constexpr int numBlocks = 1 << (sizeof(BlockId) * 8);
constexpr uint8_t maxBlockId = numBlocks - 1;

enum Name : BlockId {
    AIR = 0,
    STONE,
    STONE_BRICKS,
    DIRT,
    GRASS,
};

struct BlockData {
    // std::function<int(utils::Direction)> getTextureIdx = nullptr;
    int textureIdx = 255;

    std::optional<int> sideTextureIdx;
    std::optional<int> topTextureIdx;
    std::optional<int> bottomTextureIdx;

    int getTextureIdx(utils::Direction dir) const;

    BlockData();
};

inline std::array<BlockData, numBlocks> blockDefs = {};

void initBlocks();

}; // namespace Block
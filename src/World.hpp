#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

#include "Chunk.hpp"
#include "ChunkMesh.hpp"
#include "Player.hpp"
#include "WorldGenerator.hpp"

class WorldGenerator;

class World {
public:
    using ChunkMapType = std::unordered_map<glm::ivec2, Chunk>;
    ChunkMapType chunks;
    Player player;
    const int renderDistance = 15;
    // Max number of chunks that will be generated per frame
    const int chunkGenLimit = 3;
    int chunkGenCount = 0;

    World();

    BlockId getBlock(glm::ivec3 pos) const;
    BlockId getBlockOrGenChunk(glm::ivec3 pos);
    void setBlock(glm::ivec3 pos, BlockId block);
    void render(const Camera& camera, float aspectRatio) const;
    size_t getNumChunks() const;
    void update();
    std::pair<World::ChunkMapType::iterator, bool>
    generateChunk(glm::ivec2 worldIdx, bool createMesh);

private:
    WorldGenerator worldGen;
};
/////////////////////////////////////////////////
/// @file           game/map/block_floor.cpp
/// @author         moe-org
/// @brief          实现BlockFloor类源文件
/// @copyright      MIT License
/////////////////////////////////////////////////

#include "block_floor.hpp"
#include "mapdef.hpp"

using namespace utopia;

BlockFloor::BlockFloor() {
	for (auto x = blocks_.begin(); x != blocks_.end(); x++) {
		for(auto y = x->begin(); y != x->end(); y++) {
			y->reset(new Block());
		}
	}
}


BlockFloor& BlockFloor::operator=(BlockFloor&& origin) noexcept {
	// 移动数组
	this->blocks_ = std::move(origin.blocks_);

	return *this;
}

BlockFloor::BlockFloor(BlockFloor&& origin) noexcept {
	*this = std::move(origin);
}


std::optional<std::shared_ptr<Block>>
BlockFloor::get_block_by_pos(const FlatPos& pos) {
	// 检查坐标
	if(pos.x < 0 || pos.x >= STANDARD_BLOACK_FLOOR_X || pos.y < 0
	   || pos.y >= STANDARD_BLOACK_FLOOR_Y) {
		return std::nullopt;
	} else {
		return std::make_optional(blocks_.at(pos.x).at(pos.y));
	}
}

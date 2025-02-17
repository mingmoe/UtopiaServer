/////////////////////////////////////////////////
/// @file           game/map/block_floor.hpp
/// @author         moe-org
/// @brief          地图层定义头文件
/// @copyright      MIT License
/////////////////////////////////////////////////
#pragma once
#include "block.hpp"
#include "mapdef.hpp"
#include <array>
#include <cstdint>
#include <optional>

namespace utopia {
	/// @brief 地图层
	class BlockFloor {
	  public:
		BlockFloor();
		~BlockFloor()						 = default;

		BlockFloor(const BlockFloor& origin) = delete;
		BlockFloor& operator=(const BlockFloor& origin) = delete;

		BlockFloor(BlockFloor&& origin) noexcept;
		BlockFloor& operator=(BlockFloor&& origin) noexcept;

		/// @brief 通过坐标获取地图块
		/// @param pos 坐标
		/// @return 获取到的地图块。如果坐标不在范围内返回nullopt
		/// @note 原点在block_floor左下角。范围(0,0)-(STANDARD_BLOACK_FLOOR_X - 1, STANDARD_BLOACK_FLOOR_Y - 1)
		std::optional<std::shared_ptr<Block>>
		get_block_by_pos(const FlatPos& pos);

	  private:
		std::array<std::array<std::shared_ptr<Block>, STANDARD_BLOACK_FLOOR_Y>,
				   STANDARD_BLOACK_FLOOR_X>
			blocks_ {}; ///< 方块数组
	};

} // namespace utopia

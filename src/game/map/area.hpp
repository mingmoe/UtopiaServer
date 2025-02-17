/////////////////////////////////////////////////
/// @file           game/map/area.hpp
/// @author         moe-org
/// @brief          游戏区域定义头文件
/// @copyright      MIT License
/////////////////////////////////////////////////
#pragma once
#include "block.hpp"
#include "block_floor.hpp"
#include "mapdef.hpp"
#include <map>
#include <memory>
#include <mutex>
#include <optional>

namespace utopia {
	/// @class      Area area.hpp gmae/map/area.hpp
	/// @brief      游戏区域定义类
	class Area {
	  public:
		Area()					 = default;
		~Area()					 = default;

		Area(const Area& origin) = delete;
		Area& operator=(const Area& origin) = delete;

		Area(Area&& origin) noexcept;
		Area& operator=(Area&& origin) noexcept;

		/// @brief 通过坐标获取地图块
		/// @param pos 坐标
		/// @return 获取到的地图块。如果坐标不在范围内返回nullopt
		/// @note 原点在area左下角。范围(0,0)<->(STANDARD_BLOACK_FLOOR_X - 1, STANDARD_BLOACK_FLOOR_Y - 1)
		std::optional<std::shared_ptr<Block>> get_block_by_pos(const Pos& pos);

	  private:
		std::mutex locker_ {}; ///< 多线程锁.height_使用
		BlockFloor ground_ {}; ///< STANDARD_GROUND_Z高度层
		std::map<PosType, std::shared_ptr<BlockFloor>> ///< 其他高度层
			height_ {};
	};
} // namespace utopia

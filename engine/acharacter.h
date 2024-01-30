#pragma once

namespace ue::engine
{
	// Class Engine.Character
	// Size: 0x618 (Inherited: 0x318)
	class ACharacter : public APawn
	{
	public:
		int8 pad_0004[0x08 + 0x2f8]; // 0x288(0x238)
	};

	static_assert(sizeof(ACharacter) == 0x618);
}

#pragma once

namespace ue
{
	namespace engine
	{
		class ULocalPlayer;
	}

	// 0x70 (0x98 - 0x28)
	// Class CoreUObject.Package
	class UPackage : public UObject
	{
	public:
		uint8 pad_0001[0x70];
	};


	// 0x108 (0x130 - 0x28)
	// Class Engine.Console
	class UConsole : public UObject
	{
	public:
		uint8 pad_0001[0x10];
		engine::ULocalPlayer* console_target_player; // 0x38(0x8)
		uint8 pad_0002[0xc8];

		static UClass* static_class();
	};

	static_assert(sizeof(UConsole) == 0x108);
}

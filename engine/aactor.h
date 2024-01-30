#pragma once

namespace ue::controller
{
	class APlayerController;
}

namespace ue::engine
{
	class APawn;

	// Class Engine.Actor
	// Size: 0x290 (Inherited: 0x28)
	class AActor : public UObject
	{
	public:
		int8 pad_0001[0x158]; // 0x28(0x158)
		APawn* instigator;    // 0x180(0x08)
		int8 pad_0002[0x10];  // 0x180(0x10)
		int8 pad_0004[0x08];  // 0x198(0x08)
		int8 pad_0003[0xf0];  // 0x140(0xc8)

		float get_distance_to(AActor* other_actor);
		bool k2_teleport_to(FVector dest_location, FRotator dest_rotation);
		FVector k2_get_actor_location();
		FRotator k2_get_actor_rotation();
		FVector get_actor_bounds(bool only_colliding_components, FVector* origin, FVector* extent);
	};

	static_assert(sizeof(AActor) == 0x290);
};

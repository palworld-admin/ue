#pragma once

namespace ue::engine
{
	class UPlayer;
}

namespace ue::controller
{
	// Class Engine.PlayerController
	// Size: 0x850 (Inherited: 0x328)
	class APlayerController : public AController
	{
	public:
		int8 pad_0007[0x8];               // 0x328(0x08)
		engine::UPlayer* player;          // 0x330(0x08)
		engine::APawn* acknowledged_pawn; // 0x338(0x08)
		int8 pad_0008[0x8];               // 0x340(0x08)
		int8 player_camera_manager[0x8];  // 0x348(0x08)
		int8 pad_0009[0x500];             // 0x350(0x500)

		// // Function Engine.Controller.SetControlRotation
		// void set_control_rotation(FRotator& new_rotation)
		// {
		// 	call_function("Function Engine.Controller.SetControlRotation", new_rotation);
		// };
		//
		// // Function Engine.PlayerController.GetViewportSize
		// void get_viewport_size(int32& size_x, int32& size_y)
		// {
		// 	call_function("Function Engine.PlayerController.GetViewportSize", size_x, size_y);
		// };
		//
		// // Function Engine.PlayerController.ProjectWorldLocationToScreen
		// bool project_world_location_to_screen(FVector world_location, FVector2D& screen_location,
		//                                       bool player_viewport_relative = false)
		// {
		// 	return call_function("Function Engine.PlayerController.ProjectWorldLocationToScreen", world_location,
		// 	                     screen_location, player_viewport_relative);
		// };
	};

	static_assert(sizeof(APlayerController) == 0x850);

	/**
	 * \brief APlayerController::GetViewPoint Function Address
	 */
	inline uintptr_t get_view_point;

	/**
	 * \brief APlayerController::GetPlayerViewPoint Function Address
	 */
	inline uintptr_t get_player_view_point;
}

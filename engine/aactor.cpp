#include <ue/ue.h>

float ue::engine::AActor::get_distance_to(AActor* other_actor) {
    static UObject* fn = nullptr;
    if (!fn)
        fn = find(_("Function Engine.Actor.GetDistanceTo"));

    struct {
        AActor* other_actor;
        float return_value;
    } params{};

    params.other_actor = other_actor;
    process_event(this, fn, &params);
    return params.return_value;
}

bool ue::engine::AActor::k2_teleport_to(const FVector dest_location, const FRotator dest_rotation) {
    static UObject* fn = nullptr;
    if (!fn)
        fn = find(_("Function Engine.Actor.K2_TeleportTo"));

    struct {
        FVector dest_location;
        FRotator dest_rotation;
        bool return_value;
    } params{};

    params.dest_location = dest_location;
    params.dest_rotation = dest_rotation;

    process_event(this, fn, &params);
    return params.return_value;
}

ue::FVector ue::engine::AActor::k2_get_actor_location()
{
	static UObject* fn = nullptr;
	if (!fn)
		fn = find(_("Function Engine.Actor.K2_GetActorLocation"));

	struct {
		FVector return_value;
	} params{};

	process_event(this, fn, &params);
	return params.return_value;
}

ue::FRotator ue::engine::AActor::k2_get_actor_rotation()
{
	static UObject* fn = nullptr;
	if (!fn)
		fn = find(_("Function Engine.Actor.K2_GetActorRotation"));

	struct {
		FRotator return_value;
	} params{};

	process_event(this, fn, &params);
	return params.return_value;
}

ue::FVector ue::engine::AActor::get_actor_bounds(const bool only_colliding_components, FVector* origin, FVector* extent)
{
	static UObject* fn = nullptr;
	if (!fn)
		fn = find(_("Function Engine.Actor.GetActorBounds"));

	struct {
		bool only_colliding_components;
		FVector* origin;
		FVector* extent;
		FVector return_value;
	} params{};

	params.only_colliding_components = only_colliding_components;
	params.origin = origin;
	params.extent = extent;

	process_event(this, fn, &params);

	origin = params.origin;
	extent = params.extent;

	return params.return_value;
}




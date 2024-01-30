#pragma once

// System Libraries
#include <Windows.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <corecrt_math.h>
#include <corecrt_math_defines.h>
#include <type_traits>

// Typedefs
#include "typedefs.h"

// Utils
#include "utils.h"

// Memory
#include "memory.h"

// UE Math Primitives
#include "primitives.h"

// UE Enum
#include "enums.h"

// UE Core Array
#include "offsets.h"
#include "core/array/tarray.h"
#include "core/array/tenum.h"
#include "core/array/fnamepool.h"
#include "core/array/tobjectarray.h"

// UE Core Object
#include "core/vfunction.h"
#include "core/processevent.h"
#include "core/fstring.h"
#include "core/fname.h"
#include "core/uobject.h"
#include "core/class/ufield.h"
#include "core/class/uproperty.h"
#include "core/class/ustruct.h"
#include "core/class/uclass.h"
#include "core/class/ufunction.h"
#include "core/uconsole.h"

// UE Actor
#include "engine/aactor.h"
#include "engine/agamestatebase.h"
#include "engine/aplayerstate.h"
#include "engine/apawn.h"
#include "engine/acharacter.h"

// UE Controller
#include "engine/controller/acontroller.h"
#include "engine/controller/aplayercontroller.h"

// UE Engine
#include "engine/staticconstructobject_internal.h"
#include "engine/ulevel.h"
#include "engine/uplayer.h"
#include "engine/ugameinstance.h"
#include "engine/uworld.h"
#include "engine/uviewportclient.h"
#include "engine/ugameplaystatics.h"
#include "engine/uengine.h"
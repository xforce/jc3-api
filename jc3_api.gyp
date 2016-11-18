{
	'targets': [
	{
		'target_name': 'jc3_api',
		'type': 'static_library',
		'dependencies' : [
			'deps/jc3_hooking/jc3_hooking.gyp:jc3_hooking',
		],
		'direct_dependent_settings': {
            'include_dirs': ['.', 'deps/boost', 'deps/stl'],
        },
		'include_dirs': ['.', 'deps/boost', 'deps/stl'],
		'sources': [
			'jc3/entities/character.h',
			'jc3/entities/character.cpp',

			'jc3/entities/damageable.h',
			'jc3/entities/game_object.h',
			'jc3/entities/physics_game_object.h',
			'jc3/entities/player.h',
			'jc3/entities/vehicle.h',

			'jc3/entities/pfx/pfx_breakable.h',
			'jc3/entities/pfx/pfx_rigid_body.h',
			'jc3/entities/pfx/pfx_vehicle.h',
			'jc3/entities/pfx/pfx_game_object.h',
			'jc3/entities/pfx/pfx_instance.h',

			'jc3/spawn/spawn_system.h',
			'jc3/spawn/spawn_system.cpp',

			'jc3/ui/overlay_ui.h',
			'jc3/ui/overlay_ui.cpp',
		],
	},
	]
}
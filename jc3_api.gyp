{
	'targets': [
	{
		'target_name': 'jc3_api',
		'type': 'static_library',
		'dependencies' : [
			'deps/jc3_hooking/jc3_hooking.gyp:jc3_hooking',
		],
		'direct_dependent_settings': {
            'include_dirs': ['.'],
         },
		'sources': [
			'jc3/entities/CCharacter.h',
			'jc3/entities/CDamageable.h',
			'jc3/entities/CGameObject.h',
			'jc3/entities/CPhysicsGameObject.h',
			'jc3/entities/CPlayer.h',
			'jc3/entities/CVehicle.h',

			'jc3/entities/pfx/CPfxBreakable.h',
			'jc3/entities/pfx/CPfxRigidBody.h',
			'jc3/entities/pfx/CPfxVehicle.h',
			'jc3/entities/pfx/IPfxGameObject.h',
			'jc3/entities/pfx/IPfxInstance.h',
		],
	},
	]
}
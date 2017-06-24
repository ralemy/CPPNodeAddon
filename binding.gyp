{
  "targets": [
    {
      "target_name": "SampleAddOn",
      "sources": [ "NodeWrap/SampleObjectWrap.cpp" , "src/SampleObject.cpp"],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
       "cflags": ["-Wall", "-std=c++11"],
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-std=c++11'
        ],
      },
      "conditions": [
        [ 'OS=="mac"', {
            "xcode_settings": {
                'OTHER_CPLUSPLUSFLAGS' : ['-std=c++11','-stdlib=libc++'],
                'OTHER_LDFLAGS': ['-stdlib=libc++'],
                'MACOSX_DEPLOYMENT_TARGET': '10.9' }
            }
        ]
      ]
    }
  ]
}
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(MinimalModule)
add_subdirectory(MyModule)
add_subdirectory(NearestBlob)
add_subdirectory(ToLineCombination)
add_subdirectory(ToAngle)
add_subdirectory(VarAngFreq)
add_subdirectory(WatchRandom)
add_subdirectory(LowResBlobList)
add_subdirectory(SpeedFunction)
add_subdirectory(Compressor)
add_subdirectory(NerestPixel)
add_subdirectory(BlobSearch)
add_subdirectory(WatchSky)



set(SOURCE ${SOURCE} PARENT_SCOPE)
set(MODULES_INCLUDS ${MODULES_INCLUDS} PARENT_SCOPE)
set(MODULES_LIBS ${MODULES_LIBS} PARENT_SCOPE)

add_library(HeeModandGeoMagPuls
    SHARED
        Account.cpp
)

target_include_directories(HeeModandGeoMagPuls
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
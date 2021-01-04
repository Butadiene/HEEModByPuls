add_library(HeeModandGeoMagPuls
    SHARED
        coordinate_spec.cpp
        heembp_param.cpp
        store_data_in_memory_array.cpp
        initialize_psd.cpp
        initialize_field.cpp
)

target_include_directories(HeeModandGeoMagPuls
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
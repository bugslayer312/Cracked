add_executable(Insertion
    01_Insertion.cpp
)
target_link_libraries(Insertion
    PUBLIC Utilities)

add_executable(BinaryToString
    02_BinaryToString.cpp
)

add_executable(FlibBitToWin
    03_FlipBitToWin.cpp
)

add_executable(NextNumber
    04_NextNumber.cpp
)
target_link_libraries(NextNumber
    PUBLIC Utilities)

add_executable(Conversion
    05_Conversion.cpp
)

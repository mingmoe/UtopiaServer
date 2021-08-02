# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
# * THIS FILE IS FROM MingMoe(me@kawayi.moe)                *
# * IS LICENSED UNDER MIT                                   *
# * File:     library.cmake                                 *
# * Content:  Cmake Module                                  *
# * Copyright (c) 2020-2021 MingMoe All rights reserved.    *
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#==========================================================#
# �����򵥵ĸ�������
#==========================================================#
# �����
include(FetchContent)

function(cp_utopiaserver_add_git_library lib_name git_repo git_tag )

    # Declare
    FetchContent_Declare(
                            ${lib_name}
        GIT_REPOSITORY      ${git_repo}
        GIT_TAG             ${git_tag}
        SOURCE_DIR          ${CP_UTOPIASERVER_LIBRARY_DIR}/${lib_name}
        )

    # ȷ������ֻ����FetchContent_Populateһ��
    # �������ɴ���
    FetchContent_GetProperties(${lib_name})
    if(NOT ${lib_name}_POPULATED)
        FetchContent_Populate(${lib_name})
        
        add_subdirectory(
            ${CP_UTOPIASERVER_LIBRARY_DIR}/${lib_name}  # ����Դ�ļ�·��
            ${CP_UTOPIASERVER_BINARY_DIR}/${lib_name}   # �������·��
            EXCLUDE_FROM_ALL                            # ��������Ŀ�굱��
            )

    endif()

endfunction(cp_utopiaserver_add_git_library)

#==========================================================#
# �����
#==========================================================#
# backward-cpp
cp_utopiaserver_add_git_library(
    "backward"
    "https://github.com/bombela/backward-cpp.git"
    "v1.5"
)

target_sources(${CP_UTOPIASERVER_EXECUTABLE} PUBLIC ${BACKWARD_ENABLE})
add_backward(${CP_UTOPIASERVER_EXECUTABLE})

#==========================================================#
# ���ͷ�ļ�·��
#==========================================================#
target_include_directories(
    ${CP_UTOPIASERVER_EXECUTABLE} 
    PUBLIC ${CP_UTOPIASERVER_LIBRARY_DIR})
    
message(STATUS "Include 3rd library header directory:${CP_UTOPIASERVER_LIBRARY_DIR}")
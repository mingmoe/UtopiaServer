# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
# * THIS FILE IS FROM MingMoe(me@kawayi.moe)                *
# * IS LICENSED UNDER MIT                                   *
# * File:     install.cmake                                 *
# * Content:  Cmake Module                                  *
# * Copyright (c) 2020-2021 MingMoe All rights reserved.    *
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#==========================================================#
# ��װ��ִ���ļ�
#==========================================================#
# �������
set(UTOPIA_COMPONENT_NAME "UtopiaServerMain")

# ��װ
install(TARGETS ${CP_UTOPIASERVER_EXECUTABLE}
        # ��װ����װĿ¼��
        RUNTIME DESTINATION .
        COMPONENT ${UTOPIA_COMPONENT_NAME})


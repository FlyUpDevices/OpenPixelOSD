/* SPDX-License-Identifier: GPL-2.0-only */
/**
 * Copyright (C) 2025 Vitaliy N <vitaliy.nimych@gmail.com>
 */
#include "main.h"

void COMP3_Init(void)
{
    LL_COMP_InitTypeDef COMP_InitStruct = {0};

    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
    /**COMP3 GPIO Configuration
    PA0   ------> COMP3_INP
    PB7   ------> COMP3_OUT
    */
    GPIO_InitStruct.Pin = COMP3_INP_VIDEO_IN_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(COMP3_INP_VIDEO_IN_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = COMP3_OUT_SYNC_EXT_TRIGGER_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    GPIO_InitStruct.Alternate = LL_GPIO_AF_8;
    LL_GPIO_Init(COMP3_OUT_SYNC_EXT_TRIGGER_GPIO_Port, &GPIO_InitStruct);

    COMP_InitStruct.InputPlus = LL_COMP_INPUT_PLUS_IO1;
    COMP_InitStruct.InputMinus = LL_COMP_INPUT_MINUS_DAC1_CH1;
    COMP_InitStruct.InputHysteresis = LL_COMP_HYSTERESIS_LOW;
    COMP_InitStruct.OutputPolarity = LL_COMP_OUTPUTPOL_NONINVERTED;
    COMP_InitStruct.OutputBlankingSource = LL_COMP_BLANKINGSRC_NONE;
    LL_COMP_Init(COMP3, &COMP_InitStruct);

    /* Wait loop initialization and execution */
    /* Note: Variable divided by 2 to compensate partially CPU processing cycles */
    __IO uint32_t wait_loop_index = 0;
    wait_loop_index = (LL_COMP_DELAY_VOLTAGE_SCALER_STAB_US * (SystemCoreClock / (1000000 * 2)));
    while(wait_loop_index != 0)
    {
        wait_loop_index--;
    }
    LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_29);
    LL_EXTI_DisableFallingTrig_0_31(LL_EXTI_LINE_29);
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_29);
    LL_EXTI_EnableEvent_0_31(LL_EXTI_LINE_29);
    LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_29);
}

void COMP4_Init(void)
{
    LL_COMP_InitTypeDef COMP_InitStruct = {0};

    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
    /**COMP4 GPIO Configuration
    PB0   ------> COMP4_INP
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_0;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    COMP_InitStruct.InputPlus = LL_COMP_INPUT_PLUS_IO1;
    COMP_InitStruct.InputMinus = LL_COMP_INPUT_MINUS_DAC1_CH1;
    COMP_InitStruct.InputHysteresis = LL_COMP_HYSTERESIS_LOW;
    COMP_InitStruct.OutputPolarity = LL_COMP_OUTPUTPOL_NONINVERTED;
    COMP_InitStruct.OutputBlankingSource = LL_COMP_BLANKINGSRC_NONE;
    LL_COMP_Init(COMP4, &COMP_InitStruct);

    /* Wait loop initialization and execution */
    /* Note: Variable divided by 2 to compensate partially CPU processing cycles */
    __IO uint32_t wait_loop_index = 0;
    wait_loop_index = (LL_COMP_DELAY_VOLTAGE_SCALER_STAB_US * (SystemCoreClock / (1000000 * 2)));
    while(wait_loop_index != 0)
    {
        wait_loop_index--;
    }
    LL_EXTI_EnableRisingTrig_0_31(LL_EXTI_LINE_30);
    LL_EXTI_DisableFallingTrig_0_31(LL_EXTI_LINE_30);
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_30);
    LL_EXTI_EnableEvent_0_31(LL_EXTI_LINE_30);
    LL_EXTI_DisableIT_0_31(LL_EXTI_LINE_30);
}

#include <include_asm.h>
#include <ultra64.h>
#include <audio.h>
#include <mus/libmus.h>
#include <PR/sched.h>
#include <macros.h>
#include <audio_syms.h>

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008F9D0);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008FA24);

struct unkD_800E5090 {
    s32 unk0;
    musHandle handle;
    s32 unk8;
    s32 unkC;
};

extern struct unkD_800E5090 D_800E5090[144];

extern s32 D_800AF4E4;

extern OSSched gScheduler;

extern char _wavebankRomStart[];

s32 D_800AF320 = 0;
s32 D_800AF324 = 0;

u32 D_800AF328[][2] = {
    { ROMADDR(_binary_bin_fxbank_bin_start), ROMADDR(_binary_bin_fxbank_bin_end) },
    { ROMADDR(_binary_bin_ptrbank_bin_start), ROMADDR(_binary_bin_ptrbank_bin_end) },
    { ROMADDR(_binary_bin_song00_bin_start), ROMADDR(_binary_bin_song00_bin_end) },
    { ROMADDR(_binary_bin_song01_bin_start), ROMADDR(_binary_bin_song01_bin_end) },
    { ROMADDR(_binary_bin_song02_bin_start), ROMADDR(_binary_bin_song02_bin_end) },
    { ROMADDR(_binary_bin_song03_bin_start), ROMADDR(_binary_bin_song03_bin_end) },
    { ROMADDR(_binary_bin_song04_bin_start), ROMADDR(_binary_bin_song04_bin_end) },
    { ROMADDR(_binary_bin_song05_bin_start), ROMADDR(_binary_bin_song05_bin_end) },
    { ROMADDR(_binary_bin_song06_bin_start), ROMADDR(_binary_bin_song06_bin_end) },
    { ROMADDR(_binary_bin_song07_bin_start), ROMADDR(_binary_bin_song07_bin_end) },
    { ROMADDR(_binary_bin_song08_bin_start), ROMADDR(_binary_bin_song08_bin_end) },
    { ROMADDR(_binary_bin_song09_bin_start), ROMADDR(_binary_bin_song09_bin_end) },
    { ROMADDR(_binary_bin_song0A_bin_start), ROMADDR(_binary_bin_song0A_bin_end) },
    { ROMADDR(_binary_bin_song0B_bin_start), ROMADDR(_binary_bin_song0B_bin_end) },
    { ROMADDR(_binary_bin_song0C_bin_start), ROMADDR(_binary_bin_song0C_bin_end) },
    { ROMADDR(_binary_bin_song0D_bin_start), ROMADDR(_binary_bin_song0D_bin_end) },
    { ROMADDR(_binary_bin_song0E_bin_start), ROMADDR(_binary_bin_song0E_bin_end) },
    { ROMADDR(_binary_bin_song0F_bin_start), ROMADDR(_binary_bin_song0F_bin_end) },
    { ROMADDR(_binary_bin_song10_bin_start), ROMADDR(_binary_bin_song10_bin_end) },
    { ROMADDR(_binary_bin_song11_bin_start), ROMADDR(_binary_bin_song11_bin_end) },
    { ROMADDR(_binary_bin_song12_bin_start), ROMADDR(_binary_bin_song12_bin_end) },
    { ROMADDR(_binary_bin_song13_bin_start), ROMADDR(_binary_bin_song13_bin_end) },
    { ROMADDR(_binary_bin_song14_bin_start), ROMADDR(_binary_bin_song14_bin_end) },
    { ROMADDR(_binary_bin_song15_bin_start), ROMADDR(_binary_bin_song15_bin_end) },
    { ROMADDR(_binary_bin_song16_bin_start), ROMADDR(_binary_bin_song16_bin_end) },
};

s32 D_800AF3F0 = 0;
s32 D_800AF3F4 = 0;
s32 D_800AF3F8 = 0;
s32 D_800AF3FC = 0;

void dma_read(u32, void*, u32);
void func_8008FC14(s32*);
void func_80091C98();

void func_8008FA88()
{
    musConfig config;
    u8* banks[2];
    s32 i;

    banks[0] = gAudioFxBank;
    banks[1] = gAudioPtrBank;
    
    for (i = 0; i < 0x8F; i++)
    {
        D_800E5090[i].unkC = i + 1;
    }
    D_800E5090[0x8F].unkC = -1;

    dma_read(D_800AF328[0][0], banks[0], D_800AF328[0][1] - D_800AF328[0][0]);
    dma_read(D_800AF328[1][0], banks[1], D_800AF328[1][1] - D_800AF328[1][0]);

    bzero(&config, sizeof(musConfig));

    config.channels = 48;
    config.unk18 = 192;
    config.sched = &gScheduler;
    config.thread_priority = 12;

    config.heap = gAudioHeapPtr;
    config.heap_length = AUDIO_HEAP_SIZE;

    config.fifo_length = 64;

    config.syn_output_rate = AUDIO_SAMPLE_RATE;
    config.syn_updates = 64;
    config.syn_rsp_cmds = 4096;
    config.syn_retraceCount = 1;
    config.syn_num_dma_bufs = 64;
    config.syn_dma_buf_size = 0x800;

    MusInitialize(&config);
    MusPtrBankInitialize(&gAudioPtrBank, _wavebankRomStart);
    MusFxBankInitialize(&gAudioFxBank);
    MusFxBankSetPtrBank(&gAudioFxBank, &gAudioPtrBank);
    MusSetMasterVolume(2, 0x5FFF);
    MusSetMasterVolume(1, 0x7FFF);
    MusFxBankSetSingle(&gAudioFxBank);
    func_8008FC14(&D_800AF4E4);
    func_80091C98();
}

void func_8008FC14(s32 *arg0) {

}


INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008FC1C);


void func_8008FD0C(s32 arg0)
{
    D_800AF3F0 = arg0;
}

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008FD18);

INCLUDE_ASM(s32, "rocket/codeseg2/codeseg2_395", func_8008FEB4);

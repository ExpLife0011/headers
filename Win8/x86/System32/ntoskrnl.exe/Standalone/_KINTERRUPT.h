typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef enum _KINTERRUPT_MODE
{
  LevelSensitive = 0,
  Latched = 1,
} KINTERRUPT_MODE, *PKINTERRUPT_MODE;

typedef enum _KINTERRUPT_POLARITY
{
  InterruptPolarityUnknown = 0,
  InterruptActiveHigh = 1,
  InterruptRisingEdge = 1,
  InterruptActiveLow = 2,
  InterruptFallingEdge = 2,
  InterruptActiveBoth = 3,
} KINTERRUPT_POLARITY, *PKINTERRUPT_POLARITY;

typedef struct _KINTERRUPT
{
  /* 0x0000 */ short Type;
  /* 0x0002 */ short Size;
  /* 0x0004 */ struct _LIST_ENTRY InterruptListEntry;
  /* 0x000c */ void* ServiceRoutine /* function */;
  /* 0x0010 */ void* MessageServiceRoutine /* function */;
  /* 0x0014 */ unsigned long MessageIndex;
  /* 0x0018 */ void* ServiceContext;
  /* 0x001c */ unsigned long SpinLock;
  /* 0x0020 */ unsigned long TickCount;
  /* 0x0024 */ unsigned long* ActualLock;
  /* 0x0028 */ void* DispatchAddress /* function */;
  /* 0x002c */ unsigned long Vector;
  /* 0x0030 */ unsigned char Irql;
  /* 0x0031 */ unsigned char SynchronizeIrql;
  /* 0x0032 */ unsigned char FloatingSave;
  /* 0x0033 */ unsigned char Connected;
  /* 0x0034 */ unsigned long Number;
  /* 0x0038 */ unsigned char ShareVector;
  /* 0x003a */ unsigned short ActiveCount;
  /* 0x003c */ long InternalState;
  /* 0x0040 */ enum _KINTERRUPT_MODE Mode;
  /* 0x0044 */ enum _KINTERRUPT_POLARITY Polarity;
  /* 0x0048 */ unsigned long ServiceCount;
  /* 0x004c */ unsigned long DispatchCount;
  /* 0x0050 */ struct _KEVENT* PassiveEvent;
  /* 0x0054 */ unsigned long DispatchCode[145];
  /* 0x0298 */ void* DisconnectData;
  /* 0x029c */ struct _KTHREAD* volatile ServiceThread;
} KINTERRUPT, *PKINTERRUPT; /* size: 0x02a0 */


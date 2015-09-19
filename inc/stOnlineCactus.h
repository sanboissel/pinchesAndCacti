#ifndef __ST_ONLINE_CACTUS_H_
#define __ST_ONLINE_CACTUS_H_

typedef enum {
    NET,
    CHAIN
} cactusNodeType;

typedef struct _stOnlineCactus stOnlineCactus;

typedef struct _stCactusTree stCactusTree;

typedef struct _stCactusTreeEdge stCactusTreeEdge;

typedef struct _stCactusTreeIt stCactusTreeIt;

stOnlineCactus *stOnlineCactus_construct(stConnectivity *connectivity,
                                         void *(*edgeToEnd)(void *, bool),
                                         void *(*endToEdge)(void *));

void stOnlineCactus_destruct(stOnlineCactus *cactus);

stCactusTree *stOnlineCactus_getCactusTree(stOnlineCactus *cactus);

cactusNodeType stCactusTree_type(const stCactusTree *tree);

stCactusTreeIt *stCactusTree_getIt(stCactusTree *tree);

stCactusTree *stCactusTreeIt_getNext(stCactusTreeIt *it);

void stCactusTreeIt_destruct(stCactusTreeIt *it);

void stOnlineCactus_createEnd(stOnlineCactus *cactus, void *end);

void stOnlineCactus_addEdge(stOnlineCactus *cactus, void *end1, void *end2, void *edge);

void stOnlineCactus_deleteEdge(stOnlineCactus *cactus, void *end1, void *end2, void *edge);

void stOnlineCactus_netMerge(stOnlineCactus *cactus, void *end1, void *end2);

void stOnlineCactus_netCleave(stOnlineCactus *cactus, stCactusTree *tree, stSet *endsToRemove);

void stOnlineCactus_print(const stOnlineCactus *cactus);

void stOnlineCactus_check(stOnlineCactus *cactus);

stCactusTreeEdge *stOnlineCactus_getEdge(stOnlineCactus *cactus, void *block);

#endif

#include <gtest/gtest.h>

#include "commandmanager.h"
#include "addtarget.h"
#include "addqte.h"
#include "level.h"


/**
 * @brief instanciate test subjects
 */
CommandManager *commandManager = new CommandManager();
Level *level = new Level();
AddTarget *addTarget = new AddTarget(25, level);
AddQte *addQte = new AddQte(25, level);

/**
 * @brief TEST commandManager
 */
TEST(CommandManagerTest, undoRedoStacksEmpty) {
    EXPECT_EQ(commandManager->getUndoActionStackLength(), 0);
    EXPECT_EQ(commandManager->getRedoActionStackLength(), 0);
}

/**
 * @brief TEST addTargetQte
 */
TEST(CommandManagerTest, addTargetQte) {
    commandManager->execute(addTarget);
    commandManager->execute(addQte);

    EXPECT_EQ(commandManager->getUndoActionStackLength(), 2);
    EXPECT_EQ(commandManager->getRedoActionStackLength(), 0);
    EXPECT_EQ(level->targetsSeconds.length(), 1);
    EXPECT_EQ(level->qtesSeconds.length(), 1);
}

/**
 * @brief TEST undo
 */
TEST(CommandManagerTest, undo) {
    commandManager->undo();

    EXPECT_EQ(commandManager->getUndoActionStackLength(), 1);
    EXPECT_EQ(commandManager->getRedoActionStackLength(), 1);
    EXPECT_EQ(level->targetsSeconds.length(), 1);
    EXPECT_EQ(level->qtesSeconds.length(), 0);
}

/**
 * @brief TEST redo
 */
TEST(CommandManagerTest, redo) {
    commandManager->redo();

    EXPECT_EQ(commandManager->getUndoActionStackLength(), 2);
    EXPECT_EQ(commandManager->getRedoActionStackLength(), 0);
    EXPECT_EQ(level->targetsSeconds.length(), 1);
    EXPECT_EQ(level->qtesSeconds.length(), 1);
}

/**
 * @brief TEST fullUndo
 */
TEST(CommandManagerTest, fullUndo) {
    commandManager->undo();
    commandManager->undo();

    EXPECT_EQ(commandManager->getUndoActionStackLength(), 0);
    EXPECT_EQ(commandManager->getRedoActionStackLength(), 2);
    EXPECT_EQ(level->targetsSeconds.length(), 0);
    EXPECT_EQ(level->qtesSeconds.length(), 0);
}

/**
 * @brief main main function executed on programm call
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

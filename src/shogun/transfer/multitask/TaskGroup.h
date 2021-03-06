/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Sergey Lisitsyn, Yuyu Zhang, Björn Esser
 */

#ifndef TASKGROUP_H_
#define TASKGROUP_H_

#include <shogun/lib/config.h>

#include <shogun/base/SGObject.h>
#include <shogun/transfer/multitask/Task.h>
#include <shogun/transfer/multitask/TaskRelation.h>
#include <shogun/lib/DynamicObjectArray.h>

namespace shogun
{

/** @brief class TaskGroup used to represent a group of tasks.
 * Tasks in group do not overlap.
 *
 * @see CTask
 */
class CTaskGroup : public CTaskRelation
{
public:

	/** default constructor */
	CTaskGroup();

	/** destructor */
	virtual ~CTaskGroup();

	/** get tasks indices
	 *
	 * @return array of vectors containing indices of each task
	 */
	virtual SGVector<index_t>* get_tasks_indices() const;

	/** append task to the group
	 *
	 * @param task task to append
	 */
	void append_task(CTask* task);

	/** get number of tasks in the group
	 *
	 * @return number of tasks in the group
	 */
	virtual int32_t get_num_tasks() const;

	/** get name
	 *
	 * @return name of the object
	 */
	const char* get_name() const { return "TaskGroup"; };

	/** get relation type
	 *
	 * @return TASK_GROUP
	 */
	ETaskRelationType get_relation_type() const { return TASK_GROUP; }

private:

	/** init */
	void init();

protected:

	/** tasks of the task group */
	CDynamicObjectArray* m_tasks;

};
}
#endif


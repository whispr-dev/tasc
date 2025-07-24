import TASCEmu  # assuming bindings created as TASCEmu.so via PyBind11

grid = TASCEmu.TASCGrid(10, 10)
grid.set_cell_tag(2, 3, "add")
grid.transport_data("add", 5, "push")
grid.transport_data("add", 7, "push")
grid.transport_data("add", 0, "add")

grid.step()

result = grid.get_cell_stack_top(2, 3)
print(f"Result in cell [2,3]: {result}")

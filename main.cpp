#include <cppsim/circuit.hpp>
#include <cppsim/gate_noisy_evolution.hpp>
#include <cppsim/noisesimulator.hpp>
#include <cppsim/observable.hpp>
#include <cppsim/state.hpp>

int main()
{
    // TEST(NoisyEvolutionTest, simple_check) {
    // just check runtime error
    UINT n = 4;
    QuantumCircuit circuit(n);
    Observable hamiltonian(n);
    hamiltonian.add_operator(1., "Z 0 Z 1");
    GeneralQuantumOperator op(n), op2(n);
    std::vector<GeneralQuantumOperator *> c_ops;
    op.add_operator(1., "Z 0");
    op2.add_operator(1., "Z 1");
    c_ops.push_back(&op);
    c_ops.push_back(&op2);
    double time = 1.;
    double dt = .01;
    auto gate = gate::NoisyEvolution(&hamiltonian, c_ops, time, dt);
    circuit.add_gate(gate);
    QuantumState state(n);
    circuit.update_quantum_state(&state);
}

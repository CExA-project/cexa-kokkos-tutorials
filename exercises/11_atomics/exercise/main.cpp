#include <iostream>
#include <Kokkos_Core.hpp>

void generate_histogram (Kokkos::View<double*> histo, const int n) {

  Kokkos::parallel_for(
    n,
    KOKKOS_LAMBDA(int i) {
      histo(i % histo.size()) += i;
    });
}

int main(int argc, char *argv[]) {
  Kokkos::initialize(argc, argv);

  {
    // Initialize views
    const int N = 2'000;
    Kokkos::View<double*> histo("histo", 5);

    // Create histogram
    generate_histogram(histo, N);

    // Check result
    auto res_ = create_mirror_view(histo);
    Kokkos::deep_copy(res_, histo);

    std::cout << "res_: " << (int) res_(0) << std::endl;

    const int nsum = N / histo.size();
    const int computed_sum = (nsum * (nsum - 1) / 2) * histo.size();
    std::cout << "Computed sum:" << computed_sum << std::endl;

    std::cout << "Difference: " << computed_sum - (int)res_(0) << std::endl;
  }

  Kokkos::finalize();
}

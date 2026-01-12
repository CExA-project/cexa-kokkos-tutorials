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
		int n = 200;
		int m = 5;
		if (argc == 3) {
			n = std::atoi(argv[1]);
			m = std::atoi(argv[2]);
		}

    Kokkos::View<double*> histo("histo", m);

    // Create histogram
    generate_histogram(histo, n);

    // Check result
    auto res_ = create_mirror_view(histo);
    Kokkos::deep_copy(res_, histo);

		std::cout << "n: " << n << " m: " << m << std::endl;
    std::cout << "res_: " << (int) res_(0) << std::endl;

    const int nsum = n / m + (n%m ? 1:0);
    const int computed_sum = (nsum * (nsum - 1) / 2) * m;
    std::cout << "Computed sum:" << computed_sum << std::endl;

    std::cout << "Difference: " << computed_sum - (int)res_(0) << std::endl;
  }

  Kokkos::finalize();
}

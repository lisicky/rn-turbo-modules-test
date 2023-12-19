import {TurboModule, TurboModuleRegistry} from 'react-native';

export interface Spec extends TurboModule {
  readonly reverseString: (input: string) => string | undefined;
  readonly pointer_test1: (input: number) => number | undefined;
  readonly pointer_test2: (input: number) => number;
  readonly pointer_test3: (input: number) => number;
  readonly pointer_test4: (input: number) => number;
  readonly pointer_test5: (input: number) => number;
  readonly pointer_test6: (input: number) => number;
  readonly pointer_test7: (input: number) => number;
  readonly pointer_test8: (input: number) => number;
}

export default TurboModuleRegistry.getEnforcing<Spec>('NativeSampleModule');

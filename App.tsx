/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 */

import React from 'react';
import type {PropsWithChildren} from 'react';
// import FastImage from 'react-native-fast-image';
// import { Image } from 'expo-image';
import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
} from 'react-native';

import {
  Colors,
  DebugInstructions,
  Header,
  LearnMoreLinks,
  ReloadInstructions,
} from 'react-native/Libraries/NewAppScreen';

import NativeSampleModule from './tm/NativeSampleModule';

type SectionProps = PropsWithChildren<{
  title: string;
}>;

function Section({children, title}: SectionProps): React.JSX.Element {
  const isDarkMode = useColorScheme() === 'dark';
  return (
    <View style={styles.sectionContainer}>
      <Text
        style={[
          styles.sectionTitle,
          {
            color: isDarkMode ? Colors.white : Colors.black,
          },
        ]}>
        {title}
      </Text>
      <Text
        style={[
          styles.sectionDescription,
          {
            color: isDarkMode ? Colors.light : Colors.dark,
          },
        ]}>
        {children}
      </Text>
    </View>
  );
}

function number_to_hex_bytes(num: number): string {
  let bytes = [];
  for (let i = 0; i < 8; i++) {
    bytes.push(num & 0xff);
    num = num >> 8;
  }
  return bytes
    .reverse()
    .map(b => b.toString(16))
    .join(' ');
}

function pointers(): string {
  try {
    let pointer1 = NativeSampleModule.pointer_test1(0);
    let pointer2 = NativeSampleModule.pointer_test2(pointer1!);
    let pointer3 = NativeSampleModule.pointer_test3(pointer2);
    let pointer4 = NativeSampleModule.pointer_test4(pointer3);
    let pointer5 = NativeSampleModule.pointer_test5(pointer4);
    let pointer6 = NativeSampleModule.pointer_test6(pointer5);
    let pointer7 = NativeSampleModule.pointer_test7(pointer6);
    let pointer8 = NativeSampleModule.pointer_test8(pointer7);
    return (
      pointer1 +
      '\n' +
      number_to_hex_bytes(pointer2) +
      '\n' +
      number_to_hex_bytes(pointer3) +
      '\n' +
      number_to_hex_bytes(pointer4) +
      '\n' +
      number_to_hex_bytes(pointer5) +
      '\n' +
      number_to_hex_bytes(pointer6) +
      '\n' +
      number_to_hex_bytes(pointer7) +
      '\n' +
      number_to_hex_bytes(pointer8)
    );
  } catch (e) {
    return e.message;
  }
  // return '';
}

function App(): React.JSX.Element {
  const isDarkMode = useColorScheme() === 'dark';

  const backgroundStyle = {
    backgroundColor: isDarkMode ? Colors.darker : Colors.lighter,
  };

  return (
    <SafeAreaView style={backgroundStyle}>
      <StatusBar
        barStyle={isDarkMode ? 'light-content' : 'dark-content'}
        backgroundColor={backgroundStyle.backgroundColor}
      />
      <Text style={{color: 'red'}}>{pointers()}</Text>

      {/*<FastImage*/}
      {/*  source={{*/}
      {/*    uri: 'https://cdn-images-1.medium.com/max/1600/1*-CY5bU4OqiJRox7G00sftw.gif',*/}
      {/*  }}*/}
      {/*  source={require('./38.webp')}*/}
      {/* source={require('./image.webp')}*/}
      {/* style={{width: 400, height: 400}}*/}
      {/*/>*/}
      <ScrollView
        contentInsetAdjustmentBehavior="automatic"
        style={backgroundStyle}>
        <Header />
        <View
          style={{
            backgroundColor: isDarkMode ? Colors.black : Colors.white,
          }}>
          <Section title="Step One">
            Edit <Text style={styles.highlight}>App.tsx</Text> to change this
            screen and then come back to see your edits.
          </Section>
          <Section title="See Your Changes">
            <ReloadInstructions />
          </Section>
          <Section title="Debug">
            <DebugInstructions />
          </Section>
          <Section title="Learn More">
            Read the docs to discover what to do next:
          </Section>
          <LearnMoreLinks />
        </View>
      </ScrollView>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  sectionContainer: {
    marginTop: 32,
    paddingHorizontal: 24,
  },
  sectionTitle: {
    fontSize: 24,
    fontWeight: '600',
  },
  sectionDescription: {
    marginTop: 8,
    fontSize: 18,
    fontWeight: '400',
  },
  highlight: {
    fontWeight: '700',
  },
});

export default App;

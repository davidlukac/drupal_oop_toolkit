[![Build Status](https://travis-ci.org/davidlukac/drupal_oop_toolkit.svg)](https://travis-ci.org/davidlukac/drupal_oop_toolkit)

# OOP Toolkit for Drupal
Set of tools for working in OOP manner in Drupal 7.

__*Please note, that this work is highly experimental, in very early stages,
DRAFT version and can change dramatically!*__

Intention of this module is to provide Object Oriented interfaces and structures
for working with Drupal data, API and structures. One of the main motivations
is to avoid string references (which easily lead to bugs), manual creation of
form arrays and generally decoupled code, without obvious links.

I'm not saying that this approach is the best, or that it's going to be
successful, but I have had this in mind for quite a long time and I would like
to try it on couple of projects and get feedback from other developers.

## Components
The library so far offers following components:

- Singleton class,
- InitialisedSingleton class,
- Module class,
- Variable class,
- MenuItem class,
- Form class.

## Singleton topic
At the moment, _'static'_ components of Drupal are implemented as Singletons
(i.e. Module or MenuItem), because they should really exist only in one instance
during lifetime of the page request. I'm reading a lot about Singleton pattern,
and I think I will change the implementation later on, probably into Factory,
but the Singleton serves it's purpose for now.

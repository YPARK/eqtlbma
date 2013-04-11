/** \file samples.hpp
 *
 *  `Samples' is a class 
 *  Copyright (C) 2013 Timothee Flutre
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QUANTGEN_SAMPLES_HPP
#define QUANTGEN_SAMPLES_HPP

#include <vector>
#include <map>
#include <string>
#include <algorithm>

namespace quantgen {

  class Samples {
  private:
    vector<string> all_;
    map<string,vector<size_t> > subgroup2genotypes_;
    map<string,vector<size_t> > subgroup2explevels_;
    map<string,vector<size_t> > subgroup2covariates_;
    const vector<size_t> MapAllSamplesToTheGivenSubgroup(const vector<string> * pt_samples) const;
  public:
    Samples(void);
    size_t GetNbAll(void) const { return all_.size(); };
    bool IsPresent(const string & sample) const;
    bool IsAbsent(const string & sample) const;
    void AddSamplesIfNew(const vector<string> & samples);
    void AddSamplesFromGenotypes(const map<string,vector<string> > & subgroup2samples);
    void AddSamplesFromExplevels(const map<string,vector<string> > & subgroup2samples);
    void AddSamplesFromCovariates(const map<string,vector<string> > & subgroup2samples);
    vector<string>::const_iterator begin(void) const { return all_.begin(); };
    vector<string>::const_iterator end(void) const { return all_.end(); };
    size_t GetIndexExplevel(const size_t & idx, const string & subgroup) const;
    size_t GetIndexGenotype(const size_t & idx, const string & subgroup) const;
    size_t GetIndexCovariate(const size_t & idx, const string & subgroup) const;
    void GetCommonAndUniqueIndividualsBetweenPairOfSubgroups(
      const string & subgroup1,
      const string & subgroup2,
      vector<size_t> & inds_s1s2,
      vector<size_t> & inds_s1,
      vector<size_t> & inds_s2) const;
  };

} // namespace quantgen

#endif // QUANTGEN_SAMPLES_HPP
